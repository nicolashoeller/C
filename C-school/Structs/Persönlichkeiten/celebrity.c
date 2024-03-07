#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_LENGTH 30
#define TEMP_LINE_LENGTH 100

typedef struct{
    char firstName[NAME_LENGTH];
    char lastName[NAME_LENGTH];
    struct date{
        short day;
        short month;
        short year;
    }date;
}Person;

int print_person_year(Person person);
int search_person(char *firstName, char *lastName, int length, Person *personArray);
int count_lines(FILE *filePointer);
void output_persons(FILE *filePointer, Person *personArray);

int main(){
    FILE *filePointer;

    filePointer = fopen("celebrity.txt", "r");
    if (!filePointer)
    {
        printf("Beim Öffnen der Datei ist ein Fehler aufgetreten.\n");
        return -1;
    }
    
    int lineCount = count_lines(filePointer);

    rewind(filePointer);                                // Pointer wird auf Anfang der Datei gesetzt

    Person personArray[lineCount];

    output_persons(filePointer, personArray);

    return 0;
}

int search_person(char *firstName, char *lastName, int length, Person *personArray){
    int index;
    for(index=0; index<length; index++){
        if(!strcmp(firstName, personArray[index].firstName)){
            if(!strcmp(lastName, personArray[index].lastName)){
                return index;
            }
        }
    }
    return -1;
}

int count_lines(FILE *filePointer){
    char tempLine[TEMP_LINE_LENGTH];
    int lineCount=0;
    while(fgets(tempLine, TEMP_LINE_LENGTH, filePointer)!= NULL){
        lineCount++;
    }
    return lineCount;
}

void output_persons(FILE *filePointer, Person *personArray){
    char tempLine[TEMP_LINE_LENGTH];
    int index = 0;
    while(fgets(tempLine,TEMP_LINE_LENGTH,filePointer)!= NULL){
        char *token = strtok(tempLine, ";");
        
        strncpy(personArray[index].firstName, token, NAME_LENGTH);

        token = strtok(NULL, " ");
        while(token && strchr(token, '/') == NULL) {
            strncat(personArray[index].lastName, token, NAME_LENGTH - strlen(personArray[index].lastName) - 1);
            strncat(personArray[index].lastName, " ", NAME_LENGTH - strlen(personArray[index].lastName) - 1);
            token = strtok(NULL, " ");
        }

        if(token && strchr(token, '/') != NULL) {
            char *dateToken = strtok(token, "/");
            personArray[index].date.month = atoi(dateToken);

            dateToken = strtok(NULL, "/");
            personArray[index].date.day = atoi(dateToken);

            dateToken = strtok(NULL, "/");
            personArray[index].date.year = atoi(dateToken);
        }
        
        printf("%s %s %d/%d/%d\n", personArray[index].firstName, personArray[index].lastName, personArray[index].date.day, personArray[index].date.month, personArray[index].date.year);

        index++;
    }
}