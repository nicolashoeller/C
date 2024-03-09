/*
File: calculateMatrix.c
Date: 09.03.2024
Autor: Nicolas Höller
*/

#include <stdio.h>

void enterData(int matrix[][10], int row, int column);
void addMatrices(int matrix1[][10], int matrix2[][10], int result[][10], int row, int column);
void multiplyMatrices(int matrix1[][10], int matrix2[][10], int result[][10], int row, int column);

int main() {
    int matrix1[10][10], matrix2[10][10], result[10][10], row, column;
    printf("Enter the number of rows (between 1 and 10): ");
    scanf("%d", &row);
    printf("Enter the number of columns (between 1 and 10): ");
    scanf("%d", &column);

    printf("\nEnter elements of 1st matrix:\n");
    enterData(matrix1, row, column);

    printf("\nEnter elements of 2nd matrix:\n");
    enterData(matrix2, row, column);

    printf("\nAdding two matrices: \n");
    addMatrices(matrix1, matrix2, result, row, column);
    printf("\nMultiplying two matrices: \n");
    multiplyMatrices(matrix1, matrix2, result, row, column);

    return 0;
}

void enterData(int matrix[][10], int row, int column) {
    int i, j;
    for(i = 0; i < row; ++i) {
        for(j = 0; j < column; ++j) {
            printf("Enter element a%d%d: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void addMatrices(int matrix1[][10], int matrix2[][10], int result[][10], int row, int column) {
    int i, j;
    for(i = 0; i < row; ++i) {
        for(j = 0; j < column; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrices(int matrix1[][10], int matrix2[][10], int result[][10], int row, int column) {
    int i, j, k;
    for(i = 0; i < row; ++i) {
        for(j = 0; j < column; ++j) {
            result[i][j] = 0;
            for(k=0; k<column; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }
}