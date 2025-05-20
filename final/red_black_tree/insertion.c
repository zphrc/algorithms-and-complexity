#include <stdio.h>
#include <stdlib.h>

typedef enum {RED, BLACK} Color;

typedef struct node {
    int key;
    Color color;
    struct node* left;
    struct node* right;
    struct node* parent;
} RBNode;

void insert_fixup(RBNode **);
void leftRotate(RBNode **);
void rightRotate(RBNode **);
void inorder(RBNode *);

void insert(RBNode **, int, RBNode *);

int main() {
    RBNode *root = NULL;

    int keys[] = {
        30, 15, //60,   // initial balance, root, and basic insertions
        7, //22,        // triggers recoloring (Case 2)
        //17,           // triggers Left-Right (Case 3 → 4)
        //85, 70, 90,   // triggers Right-Left (Case 3 → 4)
        5,            // triggers Left-Left (Case 4 with recolor)
        3             // triggers Left-Left again (rotations needed)
    };
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++) {
        insert(&root, keys[i], NULL);  // assuming insert takes parent argument
        while (root->parent != NULL) root = root->parent;
        root->color = BLACK;
    }

    printf("In-order traversal (should be sorted):\n");
    inorder(root);
    printf("\n");

    return 0;
}

void leftRotate(RBNode **A) {
    RBNode *temp = (*A)->right; 
    (*A)->right = temp->left;
    if (temp->left != NULL) temp->left->parent = *A; // adjust parent pointer of left child of right child of node
    temp->parent = (*A)->parent;
    if (temp->parent != NULL) { // node has a parent
        if (temp->parent->left == *A) { // check if original node is a left child
            temp->parent->left = temp;
        } else {
            temp->parent->right = temp;
        }
    }
    temp->left = *A;
    (*A)->parent = temp;
    *A = temp;
}

void rightRotate(RBNode **A) {
    RBNode *temp = (*A)->left;
    (*A)->left = temp->right;
    if (temp->right != NULL) temp->right->parent = *A;
    temp->parent = (*A)->parent;
    if (temp->parent != NULL) { // node has a parent
        if (temp->parent->left == *A) { // check if original node is a left child
            temp->parent->left = temp;
        } else {
            temp->parent->right = temp;
        }
    }
    temp->right = *A;
    (*A)->parent = temp;
    *A = temp;
}

void inorder(RBNode *A) {
    if (A != NULL) {
        inorder(A->left);
        printf("%d(%s) [P:%d]\n", A->key, A->color == RED ? "R" : "B", A->parent ? A->parent->key : -1);
        inorder(A->right);
    }
}

void insert(RBNode **A, int key, RBNode *parent) {
    if (*A == NULL) {
        *A = (RBNode *)malloc(sizeof(RBNode));
        (*A)->key = key;
        (*A)->color = RED;
        (*A)->left = (*A)->right = NULL;                                          
        (*A)->parent = parent;
    } else {
        if (key > (*A)->key) {
            insert(&((*A)->right), key, *A);
        } else {
            insert(&((*A)->left), key, *A);
        }

        insert_fixup(A);
    }
}

// void delete(RBNode **A, int key) {

// }

void insert_fixup(RBNode **A) {
    if (*A != NULL && (*A)->parent != NULL && (*A)->parent->parent != NULL) {
        if ((*A)->color == RED && (*A)->parent->color == RED) {

            RBNode *parent = (*A)->parent;
            RBNode *grandparent = (*A)->parent->parent;
            RBNode *uncle = (parent == grandparent->left) ? grandparent->right : grandparent->left;
           
            // case 2: parent and uncle are red
            if (uncle != NULL && uncle->color == RED) {
                parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;
                insert_fixup(&grandparent);
                return;
            }

            // case 3: inner child - rotate at parent
            if (*A == parent->right && parent == grandparent->left) {
                leftRotate(&parent);
                *A = parent;
                parent = (*A)->parent;
            } else if (*A == parent->left && parent == grandparent->right) {
                rightRotate(&parent);
                *A = parent;
                parent = (*A)->parent;
            }

            // case 4: outer child - rotate at grandparent and recolor
            if (parent == grandparent->left) {
                rightRotate(&grandparent);
            } else {
                leftRotate(&grandparent);
            }

            parent = (*A)->parent;
            parent->color = BLACK;
            grandparent->color = RED;
        }
    }
}

/**
INSERT(T, z) 
1    y = T.nil
2    x = T.root
3    while x != T.nil
4        y = x
5        if z.key < x.key
6            x = x.left
7        else x = x.right
8    z.p = y
9    if y == T.nil
10        T.root = z
11    elseif z.key < y.key
12        y.left = z
13    else y.right = z
14    z.left = T.nil
15    z.right = T.nil
16    z.color = RED
17    INSERT_FIXUP(T, z)

    
*/