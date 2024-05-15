/*
File: bst.c
Date: 06.05.2024
Author: Nicolas Höller
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int value);
Node* searchNode(Node *rootNode, int value);
Node* getParentNode(Node* rootNode, Node* node);
Node* findGreatestOfLeft(Node *rootNode);
void insertNode(Node **rootNode, int value);
void printInOrder(Node *rootNode);
void deallocateNodes(Node *rootNode);
void deleteNode(Node **rootNode, Node *parent);

int main() {
    Node *rootNode = NULL;
    int choice, value;

    while(1) {
        printf("\n[*] Menu:\n");
        printf("[1] Insert a value\n");
        printf("[2] Print the tree\n");
        printf("[3] Search an element\n");
        printf("[4] Delete an element\n");
        printf("[5] Exit\n");
        printf("[+] Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\n[+] Enter the value to insert: ");
                scanf("%d", &value);
                insertNode(&rootNode, value);
                break;
            case 2:
                printf("\n[*] The elements in the tree are: ");
                printInOrder(rootNode);
                printf("\n");
                break;
            case 3:
                printf("\n[+] Enter the value to search for: ");
                scanf("%d", &value);
                Node *foundNode = searchNode(rootNode, value);
                if (foundNode != NULL) {
                    printf("[*] Value found in the tree.\n");
                } else {
                    printf("[!] Value not found in the tree.\n");
                }
                break;
            case 4:
                printf("\n[+] Enter the value to delete: ");
                scanf("%d", &value);
                foundNode = searchNode(rootNode, value);
                Node *parent = getParentNode(rootNode, foundNode);
                if (foundNode != NULL) {
                    deleteNode(&foundNode, parent);
                } else {
                    printf("[!] Value not found in the tree.\n");
                }
                break;
            case 5:
                deallocateNodes(rootNode);
                exit(0);
            default:
                printf("[!] Invalid choice. Please enter a number between 1 and 5.\n");
        }
    }

    return 0;
}

Node* searchNode(Node *rootNode, int value) {
    if (rootNode == NULL || rootNode->value == value) {
        return rootNode;
    }

    if (rootNode->value < value) {
        return searchNode(rootNode->right, value);
    }

    return searchNode(rootNode->left, value);
}

Node* createNode(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode(Node **rootNode, int value) {
    if (*rootNode == NULL) {
        *rootNode = createNode(value);
    } else if (value < (*rootNode)->value) {
        insertNode(&(*rootNode)->left, value);
    } else {
        insertNode(&(*rootNode)->right, value);
    }
}

void printInOrder(Node *rootNode) {
    if (rootNode != NULL) {
        printInOrder(rootNode->left);
        printf("%d ", rootNode->value);
        printInOrder(rootNode->right);
    }
}

void deallocateNodes(Node *rootNode) {
    if (rootNode != NULL) {
        deallocateNodes(rootNode->left);
        deallocateNodes(rootNode->right);
        free(rootNode);
    }
}

void deleteNode(Node **rootNode, Node *parent){
    if ((*rootNode)->left == NULL && (*rootNode)->right == NULL){
        if (parent->left == (*rootNode)){
            parent->left = NULL;
        }

        if (parent->right == (*rootNode)){
            parent->right = NULL;
        }

        free(*rootNode);
        *rootNode = NULL;  
    }

    if ((*rootNode)->left == NULL && (*rootNode)->right != NULL)
    {
        Node* temp = *rootNode;
        *rootNode = (*rootNode)->right;

        if (parent->left == temp) {
            parent->left = *rootNode;
        } else if (parent->right == temp) {
            parent->right = *rootNode;
        }  
        free(temp);
    }

    if ((*rootNode)->left != NULL && (*rootNode)->right == NULL)
    {
        Node* temp = *rootNode;
        *rootNode = (*rootNode)->left;
        
        if (parent->left == temp) {
            parent->left = *rootNode;
        } else if (parent->right == temp) {
            parent->right = *rootNode;
        }
        free(temp);
    }

    if ((*rootNode)->left != NULL && (*rootNode)->right != NULL)
    {
        Node *greatestOfLeft = findGreatestOfLeft((*rootNode)->left);
        Node *parentOfGreatest = getParentNode(*rootNode, greatestOfLeft);
        (*rootNode)->value = greatestOfLeft->value;

        if (greatestOfLeft->left != NULL)
        {
            Node *childOfGreatest = greatestOfLeft->left;
            if (parentOfGreatest->left == greatestOfLeft) {
                parentOfGreatest->left = childOfGreatest;
            } else {
                parentOfGreatest->right = childOfGreatest;
            }
        } 
        else {
            if (parentOfGreatest->left == greatestOfLeft) {
                parentOfGreatest->left = NULL;
            } else {
                parentOfGreatest->right = NULL;
            }
        }

        free(greatestOfLeft);
    }
    
}

Node* getParentNode(Node* rootNode, Node* node) {
    if (rootNode == node) {
        return NULL;
    }

    if (rootNode->left == node || rootNode->right == node) {
        return rootNode;
    }

    if (node->value < rootNode->value) {
        return getParentNode(rootNode->left, node);
    } else if (node->value > rootNode->value) {
        return getParentNode(rootNode->right, node);
    }

    return NULL;
}

Node* findGreatestOfLeft(Node *rootNode){
    if (rootNode == NULL) {
        return NULL;
    }

    if (rootNode->right == NULL) {
        return rootNode;
    }
    
    findGreatestOfLeft(rootNode->right);
}