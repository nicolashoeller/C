#include "bstreelib.h"

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

void printBranchHeights(Node *node, int height) {
    if (node == NULL) {
        return;
    }
    printf("Height of branch with root value %d: %d\n", node->value, height);
    printBranchHeights(node->left, height + 1);
    printBranchHeights(node->right, height + 1);
}