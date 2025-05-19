#include <stdio.h>
#include <stdlib.h>
#define NUM_CHARS 256

typedef enum {TRUE, FALSE} Boolean;

typedef struct node {
    struct node *children[NUM_CHARS];
    Boolean terminal;
} TrieNode;

TrieNode *createNode() {
    TrieNode *newNode = (TrieNode *)malloc(sizeof(TrieNode));

    int x;
    for (x = 0; x < NUM_CHARS; x++) {
        newNode->children[x] = NULL;
    }
}

int main() {

    printf("%d", sizeof(int));
    return 0;
}