#include<stdio.h>
#include<stdlib.h>
typedef struct avlnode {
    int key;
    struct avlnode* left;
    struct avlnode* right;
    int height;
}avl;
int getHeight(avl* n){
    if(n==NULL){
        return 0;
    }
    return n->height;
}
avl* createNode(int key){
    avl* node = (avl*)malloc(sizeof(avl));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}
int max(int a,int b){
    return (a>b) ? a : b;
}
int getBalanceFactor(avl* n){
    if(n==NULL){
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}
avl* rightrotate(avl* y){
    avl* x = y->left;
    avl* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(getHeight(y->left),getHeight(y->right))+1;
    x->height = max(getHeight(x->left),getHeight(x->right))+1;
    return x;
}
avl* leftrotate(avl* x){
    avl* y = x->right;
    avl* T2 = y->left;
    y->left = x;
    x->right = T2;
    y->height = max(getHeight(y->left),getHeight(y->right))+1;
    x->height = max(getHeight(x->left),getHeight(x->right))+1; 
    return y;
}
avl* insert(avl* node,int key){
    if(node==NULL){
        return createNode(key);
    }
    if(key<node->key){
        node->left = insert(node->left,key);
    }else if(key>node->key){
        node->right = insert(node->right,key);
    }else{
        return node;
    }
    node->height = 1+max(getHeight(node->left),getHeight(node->right));
    int balance = getBalanceFactor(node);
    if(balance>1 && key < node->left->key){
        return rightrotate(node);
    }
    if(balance<-1 && key > node->right->key){
        return leftrotate(node);
    }
    if(balance > 1 && key > node->left->key){
        node->left = leftrotate(node->left);
        return rightrotate(node);
    }
    if(balance < -1 && key < node->right->key){
        node->right = rightrotate(node->right);
        return leftrotate(node);
    }
    return node;
}
void inOrder(avl* root)
{
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}
int main(){
    avl* root = NULL;
    root = insert(root, 31);
    root = insert(root,23);
    root = insert(root, 58);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 49);
    root = insert(root, 22);
    root = insert(root, 24);
    root = insert(root, 50);
    root = insert(root, 51);
    inOrder(root);
}
/*
Time Complexity(for all operations): O(log(n))
Space Complexity: O(log(n)) for searching, O(1) for insertion and deletion.
for n nodes.
The avl tree is a self balancing binary search tree that self balances based on the
height difference between left and right subtrees.We apply different rotations based
on the balance difference
RR(right rotate): applied when node is unbalanced due to insertion in left subtree
The solution is to take the unbalanced node and rotate it's top edge 90 degrees 
to the right.
on the balance difference
LL(left rotate): applied when node is unbalanced due to insertion in right subtree
The solution is to take the unbalanced node and rotate it's top edge 90 degrees 
to the left.
LR(left right rotation):applied when a left child of a node is right heavy.Perform a 
left rotation on the left child, then a right rotation on the original node.
RL(right left rotation):applied when right child of a node is left heavy. Perfrom a right
rotation on the right child, then a left rotation on the original node.
*/