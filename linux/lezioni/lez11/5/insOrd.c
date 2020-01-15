#include <stdlib.h>
#include <stdio.h>

#define True 1
#define False 0
#define STRING_FORMAT_NODE "%d -> "
#define STRING_END_LIST "NULL \n"

typedef struct node {
    int value;
    struct node *nextNode;
} node;
typedef node *nodePtr;

void cleanBuffer(void);

int readInt(void);

nodePtr allocNode(void);

void checkPtr(void *);

void insOrd_REC(nodePtr *);

void printList_REC(nodePtr);

int main(void) {
    nodePtr root = NULL;

    insOrd_REC(&root);
    printList_REC(root);

    return 0;
}

void cleanBuffer(void) {
    scanf("%*[^\n]%*c");
}

int readInt(void) {
    int res;

    while (scanf("%d", &res) != 1) {
        cleanBuffer();
    }
    cleanBuffer();

    return res;
}

nodePtr allocNode(void) {
    return calloc(1, sizeof(node));
}

void checkPtr(void *ptr) {
    if (ptr == NULL) {
        exit(EXIT_FAILURE);
    }
}

void insOrd_REC(nodePtr *rootPtr) {
    nodePtr newNode = allocNode();
    checkPtr(newNode);
    newNode->value = readInt();
    newNode->nextNode = NULL;

    if (newNode->value > -1) {

        nodePtr prevPtr = NULL;
        nodePtr currPtr = *rootPtr;

        while (currPtr != NULL && newNode->value > currPtr->value) {
            prevPtr = currPtr;
            currPtr = prevPtr->nextNode;
        };
        if (prevPtr == NULL){
            // update root
            newNode->nextNode = *rootPtr;
            *rootPtr = newNode;
        } else if (currPtr == NULL) {
            // add in tail
            prevPtr->nextNode = newNode;
        } else {
            // add in between
            prevPtr->nextNode = newNode;
            newNode->nextNode = currPtr;
        }

        insOrd_REC(rootPtr);
    }
}

void printList_REC(nodePtr currPtr) {
    if (currPtr != NULL) {
        printf(STRING_FORMAT_NODE, currPtr->value);
        printList_REC(currPtr->nextNode);
    } else {
        printf(STRING_END_LIST);
    }
}
