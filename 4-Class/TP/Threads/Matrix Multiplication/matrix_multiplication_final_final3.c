/*
File: matrix_multiplication_no_structs.c
Date: 26.12.2024
Autor: Nicolas Höller (angepasst von ChatGPT)
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1000000
#define THREAD_COUNT 4

int readMatrixFromFile(char *filename, int *matrix, int numRows, int numColumns);
int writeMatrixToFile(char *filename);
int calculateElement(int row, int col);
void *performMatrixMultiplication(void *arg);
void readMatrixColumnsAndRows(char* filename, int* row, int* column);

int global_startRow[THREAD_COUNT];
int global_endRow[THREAD_COUNT];
int global_numColumnsA;
int global_numColumnsB;
int global_numRowsA;
int global_numRowsB;
int *global_matrixA;
int *global_matrixB;
int *global_resultMatrix;

int main() {
    char* filename1 = "MatrixA.csv";
    char* filename2 = "MatrixB.csv";
    char* outputFilename = "output.csv";

    readMatrixColumnsAndRows(filename1, &global_numRowsA, &global_numColumnsA);
    readMatrixColumnsAndRows(filename2, &global_numRowsB, &global_numColumnsB);

    if (global_numColumnsA != global_numRowsB) {
        printf("Matrixmultiplikation nicht möglich: Spalten von %s (%d) != Zeilen von %s (%d).\n", filename1, global_numColumnsA, filename2, global_numRowsB);
        return EXIT_FAILURE;
    }

    printf("%s: %d Zeilen, %d Spalten\n", filename1, global_numRowsA, global_numColumnsA);
    printf("%s: %d Zeilen, %d Spalten\n", filename2, global_numRowsB, global_numColumnsB);
    printf("\n");

    global_matrixA = malloc(global_numRowsA * global_numColumnsA * sizeof(int));
    global_matrixB = malloc(global_numRowsB * global_numColumnsB * sizeof(int));
    global_resultMatrix = malloc(global_numRowsA * global_numColumnsB * sizeof(int));

    if (!global_matrixA || !global_matrixB || !global_resultMatrix) {
        printf("Speicher konnte nicht zugewiesen werden\n");
        return EXIT_FAILURE;
    }

    if (readMatrixFromFile(filename1, global_matrixA, global_numRowsA, global_numColumnsA) < 0) {
        return EXIT_FAILURE;
    }

    if (readMatrixFromFile(filename2, global_matrixB, global_numRowsB, global_numColumnsB) < 0) {
        return EXIT_FAILURE;
    }

    pthread_t threads[THREAD_COUNT];
    int rowsPerThread = global_numRowsA / THREAD_COUNT;

    for (int i = 0; i < THREAD_COUNT; i++) {
        global_startRow[i] = i * rowsPerThread;
        if (i == THREAD_COUNT - 1) {
            global_endRow[i] = global_numRowsA;
        } else {
            global_endRow[i] = (i + 1) * rowsPerThread;
        }

        pthread_create(&threads[i], NULL, performMatrixMultiplication, (void *)(long)i);
    }

    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    if (writeMatrixToFile(outputFilename) < 0) {
        return EXIT_FAILURE;
    }

    printf("Ergebnis in '%s' gespeichert.\n", outputFilename);

    free(global_matrixA);
    free(global_matrixB);
    free(global_resultMatrix);

    return 0;
}

int readMatrixFromFile(char *filename, int *matrix, int numRows, int numColumns) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Fehler beim Öffnen der Datei");
        return -1;
    }

    char buffer[MAX_BUFFER_SIZE];
    int currentRow = 0;

    while (fgets(buffer, sizeof(buffer), file) && currentRow < numRows) {
        int currentColumn = 0;
        char *token = strtok(buffer, ";");
        while (currentColumn < numColumns) {
            matrix[currentRow * numColumns + currentColumn] = atoi(token);
            currentColumn++;
            token = strtok(NULL, ";");
        }
        currentRow++;
    }

    fclose(file);
    return 0;
}

int writeMatrixToFile(char *filename) {
    FILE *file = fopen(filename, "w+");
    if (!file) {
        perror("Fehler beim Öffnen der Datei");
        return -1;
    }

    for (int i = 0; i < global_numRowsA; i++) {
        for (int j = 0; j < global_numColumnsB; j++) {
            fprintf(file, "%d", global_resultMatrix[i * global_numColumnsB + j]);
            if (global_numColumnsB - 1 > j) {
                fprintf(file, ";");
            }
        }
        fprintf(file, "\n");
    }

    fclose(file);
    return 0;
}

int calculateElement(int row, int col) {
    int sum = 0;
    for (int k = 0; k < global_numColumnsA; k++) {
        int elementA = global_matrixA[row * global_numColumnsA + k];
        int elementB = global_matrixB[k * global_numColumnsB + col];
        sum += elementA * elementB;
    }
    return sum;
}

void *performMatrixMultiplication(void *arg) {
    int threadIndex = (int)(long)arg;

    for (int row = global_startRow[threadIndex]; row < global_endRow[threadIndex]; row++) {
        for (int col = 0; col < global_numColumnsB; col++) {
            int resultElement = calculateElement(row, col);
            global_resultMatrix[row * global_numColumnsB + col] = resultElement;
        }
    }

    return NULL;
}

void readMatrixColumnsAndRows(char* filename, int* row, int* column) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Fehler beim Öffnen der Datei");
        return;
    }

    char line[MAX_BUFFER_SIZE];
    (*column) = 0;
    (*row) = 0;

    while (fgets(line, sizeof(line), file)) {
        (*row)++;
    }

    for (int i = 0; line[i] != '\0'; i++){
        if (line[i] == ';') {
           (*column)++;
        }
    }

    (*column)++;

    fclose(file);
}
