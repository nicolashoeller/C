#ifndef __BSTREE_H__
#define __BSTREE_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

struct Node* createNode(int value);
struct Node* searchNode(Node *rootNode, int value);
struct Node* getParentNode(Node* rootNode, Node* node);
struct Node* findGreatestOfLeft(Node *rootNode);
void insertNode(Node **rootNode, int value);
void printInOrder(Node *rootNode);
void deallocateNodes(Node *rootNode);
void deleteNode(Node **rootNode, Node *parent);
void printBranchHeights(Node *node, int height);

#endif