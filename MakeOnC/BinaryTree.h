#ifndef BINARY_TREE_H
#define BINARY_TREE_H

struct Node 
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value);
void insertNode(struct Node** root, int value);
void inorderTraversal(struct Node* root);
void showTree(const struct Node* root);
#endif
