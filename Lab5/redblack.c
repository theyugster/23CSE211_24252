#include <stdio.h>
#include <stdlib.h>

typedef enum { RED, BLACK } Color;

typedef struct Node {
    int data;
    Color color;
    struct Node *left, *right, *parent;
} Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = node->parent = NULL;
    node->color = RED; 
    return node;
}
void leftRotate(Node** root, Node* x) {
    Node* y = x->right;
    x->right = y->left;
    if (y->left != NULL) y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL) *root = y;
    else if (x == x->parent->left) x->parent->left = y;
    else x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void rightRotate(Node** root, Node* y) {
    Node* x = y->left;
    y->left = x->right;
    if (x->right != NULL) x->right->parent = y;
    x->parent = y->parent;
    if (y->parent == NULL) *root = x;
    else if (y == y->parent->left) y->parent->left = x;
    else y->parent->right = x;
    x->right = y;
    y->parent = x;
}
void fixViolation(Node** root, Node* z) {
    while (z != *root && z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            Node* y = z->parent->parent->right; // Uncle
            if (y != NULL && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(root, z->parent->parent);
            }
        } else {
            Node* y = z->parent->parent->left; 
            if (y != NULL && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(root, z->parent->parent);
            }
        }
    }
    (*root)->color = BLACK;
}

void insert(Node** root, int data) {
    Node* z = createNode(data);
    Node* y = NULL;
    Node* x = *root;

    while (x != NULL) {
        y = x;
        if (z->data < x->data) x = x->left;
        else x = x->right;
    }
    z->parent = y;
    if (y == NULL) *root = z;
    else if (z->data < y->data) y->left = z;
    else y->right = z;

    fixViolation(root, z);
}

void inOrder(Node* root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d(%s) ", root->data, root->color == RED ? "R" : "B");
    inOrder(root->right);
}

int main() {
    Node* root = NULL;
    int arr[] = {31, 23, 58, 10, 30, 49, 22, 24, 50, 51};
    for(int i=0; i<10; i++) insert(&root, arr[i]);

    printf("Inorder Traversal of RB Tree:\n");
    inOrder(root);
    return 0;
}
/*
Time Complexity: O(log n) for all operations 
Space Complexity: O(n) to store the tree, O(log n) stack space for recursion.
The Red-Black tree is a self-balancing binary search tree that maintains balance 
using a node "color" property (Red or Black) and a specific set of rules. 
Unlike AVL trees, which are strictly balanced by height, Red-Black trees are 
"loosely" balanced, requiring fewer rotations during insertion and deletion.
The Balancing Rules:
Root Property: The root is always Black.
External Property: Every leaf (NULL) is Black.
Internal Property: If a node is Red, both its children must be Black (No two Reds in a row).
Depth Property: Every path from a node to its descendant NULL nodes must contain the same number of 
Black nodes.
*/