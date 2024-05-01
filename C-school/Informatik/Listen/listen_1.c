/*
File: dynamische_listen_1.c
Date: 01.05.2024
Autor: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int x;
    struct Node *next;
} Node;

void printLinkedLists(Node *rootNode);

int main(int argc, char* argv[])
{
    Node rootNode;

    rootNode.x = 13;
    rootNode.next = malloc(sizeof(Node));
    
    rootNode.next->x = 2;
    rootNode.next->next = malloc(sizeof(Node));

    rootNode.next->next->x = 4;
    rootNode.next->next->next = NULL;

    printLinkedLists(&rootNode);
    free(rootNode.next->next);
    free(rootNode.next);

    return 0;
}

void printLinkedLists(Node * rootNode){
    Node * current = rootNode;
    int i = 1;
    while (current != NULL){
        printf("Element %d: %d\n", i, current->x);
        current = current->next;
        i++;
    }
}