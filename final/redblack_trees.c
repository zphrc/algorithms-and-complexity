/**
 * Red-Black Trees - Study Notes and Documentation
 * -----------------------------------------------
 * Definition:
 *   - A Red-Black Tree is a self-balancing binary search tree (BST).
 *   - Nodes are colored either RED or BLACK to enforce balancing rules.
 *
 * Properties:
 *   1. Every node is either RED or BLACK
 *   2. The root is always BLACK
 *   3. Red nodes cannot have red children (no two reds in a row)
 *   4. Every path from a node to its descendant NULL nodes has the same number of BLACK nodes
 *   5. New nodes are inserted RED (fix-up is applied afterward)
 *
 * Key Operations:
 *   - Insertion: O(log n)
 *   - Deletion:  O(log n)
 *   - Search:    O(log n)
 *
 * Balancing:
 *   - Maintained via a combination of:
 *       • Rotations (left or right)
 *       • Recoloring of nodes
 *   - Ensures tree remains roughly balanced with minimal height
 *
 * Comparison with AVL Trees:
 *   - Red-Black Trees are more flexible (allow looser balancing)
 *   - May have slightly worse search performance than AVL
 *   - Insertion and deletion are often faster in practice
 *
 * Implementation Note:
 *   - Each node must track both its color and child pointers
 *   - Fix-up procedures are required after insertions and deletions to restore properties
 */

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

void validate(RBNode **);
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

        validate(A);
    }
}

void delete(RBNode **A, int key) {

}

void validate(RBNode **A) {
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
                validate(&grandparent);
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