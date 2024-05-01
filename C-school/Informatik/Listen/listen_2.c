/*
File: listen_2.c
Date: 01.05.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int x;
    struct Node *next;
} Node;

int enterValue();
void insertElement(Node **rootNode);
void _insertElement(Node **rootNode, int value);
void printLinkedLists(Node *rootNode);

int main(int argc, char* argv[])
{
    Node *rootNode = NULL;
    int value;


    insertElement(&rootNode);

    printLinkedLists(rootNode);
    free(rootNode);

    return 0;
}

int enterValue(){
    int value;
    printf("Int Value: ");
    scanf("%d", &value);
    return value;
}

void insertElement(Node **rootNode){
    int value = enterValue();
    _insertElement(rootNode, value);
}

void _insertElement(Node **rootNode, int value){
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Error while allocating memory.");
        exit(1);
    }
    
    newNode->next = NULL;
    newNode->x = value;

    if (*rootNode == NULL)
    {
        *rootNode = newNode;
        if (rootNode == NULL)
        {
            printf("Error while allocating memory.");
            exit(1);
        }
        return;
    }

    Node *current = *rootNode;

    while (current->next != NULL){
        current = current->next;
    }

    current->next = newNode;
}

void printLinkedLists(Node *rootNode){
    Node * current = rootNode;
    int i = 1;
    while (current != NULL){
        printf("Element %d: %d\n", i, current->x);
        current = current->next;
        i++;
    }
}