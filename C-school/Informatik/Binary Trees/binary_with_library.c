/*
File: binary_st.c
Date: 27.05.2024
Autor: Nicolas Höller
*/

#include "bstreelib.h"

int main(int argc, char* argv[])
{
    Node* rootNode;
    insertNode(&rootNode, 5);
    printInOrder(rootNode);
    deallocateNodes(rootNode);

    return 0;
}