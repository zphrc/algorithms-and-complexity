/*
 * AVL Trees - Study Notes and Documentation
 * -----------------------------------------
 * Definition:
 *   - AVL Tree (Adelson-Velsky and Landis Tree) is a self-balancing binary search tree (BST).
 *   - For every node, the height difference (balance factor) between its left and right subtrees is at most 1.
 *
 *   - Balance Factor = height(left subtree) - height(right subtree)
 *   - Allowed balance factors: -1, 0, 1
 *
 * Key Operations:
 *   - Insertion: O(log n)
 *   - Deletion: O(log n)
 *   - Search:   O(log n)
 *
 * Rebalancing is done using rotations:
 *
 *   1. Single Rotations:
 *      a) Left Rotation (for Right-Right imbalance)
 *      b) Right Rotation (for Left-Left imbalance)
 *
 *   2. Double Rotations:
 *      a) Left-Right Rotation (for Left-Right imbalance)
 *      b) Right-Left Rotation (for Right-Left imbalance)
 *
 * Example:
 *   Insert: 10 → 20 → 30
 *   This is a Right-Right (RR) imbalance. Apply Left Rotation at node 10.
 *
 *   Before:
 *       10
 *         \
 *         20
 *           \
 *           30
 *
 *   After Left Rotation at 10:
 *       20
 *      /  \
 *     10  30
 *
 * Use Cases:
 *   - Ordered dictionaries/maps
 *   - Memory indexing
 *   - Databases and file systems needing balanced BSTs
 *
 * Implementation Note:
 *   Each node stores its height to compute balance factors efficiently.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    int height;
    struct node* left;
    struct node* right;
} AVLNode;

typedef enum {TRUE, FALSE} boolean;

int max(int, int);
int height(AVLNode *);
void updateHeight(AVLNode *);
int getBalance(AVLNode *);
void rightRotate(AVLNode **);
void leftRotate(AVLNode **);
void inorder(AVLNode *);
AVLNode *minNode(AVLNode *);

void insert(AVLNode **, int);
void delete(AVLNode **, int);
boolean search(AVLNode *, int);

int main() {
    AVLNode *root = NULL;

    int keys[] = {10, 20, 30, 40, 50, 25};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++) {
        insert(&root, keys[i]);
    }

    printf("In-order traversal of AVL tree: ");
    inorder(root);
    printf("\n");

    delete(&root, 30);
    printf("In-order after deleting 30: ");
    inorder(root);
    printf("\n");

    printf("Searching 50...\n");
    (search(root, 50)) ? printf("Did not find 50.") : printf("Found 50!");
    printf("\n");

    printf("Searching 70...\n");
    (search(root, 70)) ? printf("Did not find 70.") : printf("Found 70!");
    printf("\n");

    return 0;
}

int max(int a, int b) {
    return (a < b) ? b : a;
}

int height(AVLNode *A) {
    return (A == NULL) ? 0 : A->height;
}

void updateHeight(AVLNode *A) {
    if (A != NULL) {
        A->height = 1 + max(height(A->left), height(A->right));
    }
}

int getBalance(AVLNode *A) {
    return height(A->left) - height(A->right);
}

void rightRotate(AVLNode **A) {
    AVLNode *temp = (*A)->left;
    (*A)->left = temp->right;
    temp->right = *A;
    *A = temp;

    updateHeight(temp->right);
    updateHeight(temp);
}

void leftRotate(AVLNode **A) {
    AVLNode *temp = (*A)->right;
    (*A)->right = temp->left;
    temp->left = *A;
    *A = temp;

    updateHeight(temp->left);
    updateHeight(temp);
}

void inorder(AVLNode *A) {
    if (A != NULL) {
        inorder(A->left);
        printf("%d ", A->key);
        inorder(A->right);
    }
}

AVLNode *minNode(AVLNode *A) {
    return (A == NULL)? NULL : ((A->left == NULL) ? A : minNode(A->left));
}

void insert(AVLNode **A, int key) {
    if (*A == NULL) {
        *A = (AVLNode*)malloc(sizeof(AVLNode));
        if (*A != NULL) {
            (*A)->key = key;
            (*A)->height = 1;
            (*A)->left = (*A)->right = NULL;
        }
    } else {
        if (key > (*A)->key) {
            insert(&((*A)->right), key); 
        } else {
            insert(&((*A)->left), key);
        }

        updateHeight(*A);
        int balance = getBalance(*A);

        if (balance > 1) {
            if (key < (*A)->left->key) {
                rightRotate(A);
            } else {
                leftRotate(&((*A)->left));
                rightRotate(A);
            }
        } else if (balance < -1) {
            if (key > (*A)->right->key) {
                leftRotate(A);
            } else {
                rightRotate(&((*A)->right));
                leftRotate(A);
            }
        }
    }
}

void delete(AVLNode **A, int key) {
    if (*A != NULL) {

        AVLNode *temp;

        if (key > (*A)->key) {
            delete(&((*A)->right), key);
        } else if (key < (*A)->key) {
            delete(&((*A)->left), key);
        } else {
            if ((*A)->left == NULL && (*A)->right == NULL) {
                free(*A);
                (*A) = NULL;
            } else if ((*A)->left != NULL && (*A)->right != NULL) {
                temp = minNode((*A)->right);
                (*A)->key = temp->key;
                delete(&((*A)->right), (*A)->key);
            } else if ((*A)->left != NULL || (*A)->right != NULL) {
                temp = (*A)->left ? (*A)->left : (*A)->right;
                free(*A);
                *A = temp;
            }
        }

        // update height & rebalance
        updateHeight(*A);
        int balance = getBalance(*A);
        
        if (balance > 1) {
            if (getBalance((*A)->left) >= 0) {
                rightRotate(A);
            } else {
                // the left child's right subtree is heavier.
                leftRotate(&((*A)->left));
                rightRotate(A);
            }
        } else if (balance < -1) {
            if (getBalance((*A)->right) >= 0) {
                leftRotate(A);
            } else {
                // the right child's left subtree is heavier.
                rightRotate(&((*A)->right));
                leftRotate(A);
            }
        }
    }
}

boolean search(AVLNode *A, int key) {
    boolean found = FALSE;
    if (A != NULL) {
        if (A->key == key) {
            found = TRUE;
        } else if (key > A->key) {
            found = search(A->right, key);
        } else if (key < A->key) {
            found = search(A->left, key);
        }
    }
    return found;
}
