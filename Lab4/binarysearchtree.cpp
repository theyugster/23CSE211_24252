#include<stdio.h>   
#include<stdlib.h>   
typedef struct Node{   
    int data;   
    struct Node* left;   
    struct Node* right;   
}Node;   
Node* createNode(int newdata){   
    Node* newnode = (Node*)malloc(sizeof(Node));   
    newnode->data = newdata;   
    newnode->left = NULL;   
    newnode->right = NULL;   
    return newnode;   
}   
void insert(Node** root, int data){   
    if(*root == NULL){   
        *root = createNode(data);   
        return;   
    }   
    if(data < (*root)->data){   
        insert(&(*root)->left, data);   
    } else if(data > (*root)->data){   
        insert(&(*root)->right, data);   
    }   
}  
Node* findMin(Node* root) { 
    while(root && root->left != NULL) { 
        root = root->left; 
    } 
    return root; 
} 
Node* del(Node* root, int val){   
    if(root == NULL){   
        printf("Tree empty or value not found\n");   
        return root;   
    } 
    if(val < root->data) { 
        root->left = del(root->left, val); 
    } else if(val > root->data) { 
        root->right = del(root->right, val); 
    } else { 
        if(root->left == NULL) { 
            Node* temp = root->right; 
            free(root); 
            return temp; 
        } else if(root->right == NULL) { 
            Node* temp = root->left; 
            free(root); 
            return temp; 
        } 
        Node* temp = findMin(root->right); 
        root->data = temp->data; 
        root->right = del(root->right, temp->data); 
    } 
    return root; 
}   
Node* search(Node* root, int val){   
    if(root == NULL || root->data == val){   
        return root;   
    }   
    if(val < root->data){   
        return search(root->left, val);   
    } else {   
        return search(root->right, val);   
    }   
}   
void inorderTraversal(Node* root) {   
    if (root == NULL) {   
        return;   
    }   
    inorderTraversal(root->left);   
    printf("%d ", root->data);   
    inorderTraversal(root->right);   
}   
void preorderTraversal(Node* root) {   
    if (root == NULL) {   
        return;   
    }   
    printf("%d ", root->data);   
    preorderTraversal(root->left);   
    preorderTraversal(root->right);   
}   
void postorderTraversal(Node* root) {   
    if (root == NULL) {   
        return;   
    }   
    postorderTraversal(root->left);   
    postorderTraversal(root->right);   
    printf("%d ", root->data);   
}   
int main() {  
    Node* root = NULL;   
    insert(&root, 50);  
    insert(&root, 30);   
    insert(&root, 70);   
    insert(&root, 20);   
    insert(&root, 40);   
    insert(&root, 60);   
    insert(&root, 80);   
    printf("Inorder traversal (sorted): ");   
    inorderTraversal(root);   
    printf("\n");   
    printf("Preorder traversal: ");   
    preorderTraversal(root);   
    printf("\n"); 
    printf("Postorder traversal: ");   
    postorderTraversal(root);   
    printf("\n"); 
    int deleteValue = 20;   
    printf("After deletion of %d: ", deleteValue);   
    root = del(root, deleteValue);   
    inorderTraversal(root);   
    printf("\n");   
    int insertValue = 25;   
    insert(&root, insertValue);   
    printf("After insertion of %d: ", insertValue);   
    inorderTraversal(root);   
    printf("\n");   
    int target = 25;   
    Node* searchResult = search(root, target);   
    if (searchResult != NULL) {   
        printf("Node %d found in the BST.\n", target);   
    } else {   
        printf("Node %d not found in the BST.\n", target);   
    }  
    target = 100; 
    searchResult = search(root, target);   
    if (searchResult != NULL) {   
        printf("Node %d found in the BST.\n", target);   
    } else {   
        printf("Node %d not found in the BST.\n", target);   
    } 
    return 0;   
} 

/*
Time Complexity:O(logn), worst O(n)
Space Complexity:O(logn), worst O(n)
This program implements a Binary Search Tree (BST) using a recursive approach.
The tree maintains the BST property where values smaller than a node are stored in the left subtree 
and larger values in the right subtree.
Insertion and searching work by recursively comparing the given value with the current node and 
moving left or right accordingly until the correct position or value is found.
Deletion is handled by recursively locating the target node and managing three cases: node with no 
children, node with one child, and node with two children (replaced using its inorder successor).
Traversals operate on the principle of recursion:
inorder traversal visits left->root->right(producing sorted output),
preorder traversal visits root->left->right
postorder is left->right-root
The recursive process continues until a null pointer is reached, which acts as the base case.
*/