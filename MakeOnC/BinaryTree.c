#include "BinaryTree.h"
#include <stdlib.h>
#include <stdio.h>
#include<stdbool.h>


struct Node* createNode(int value)
{
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->data = value;
    root->left = NULL;
    root->right = NULL;
    return root;
}
void insertNode(struct Node** root, int value)
{
    if(*root == NULL)
    {
       *root = (struct Node*) malloc(sizeof(struct Node));
       (*root)->data = value;
       (*root)->left = NULL;
       (*root)->right = NULL;  
    }
    else 
    {
        struct Node* curr = *(root);
        while (curr != NULL) 
        {
            if(value == curr->data)
            {
                return;
            }
            else if(value < curr->data )
            {
                if(curr->left == NULL)
                {
                    curr->left = (struct Node*)malloc(sizeof(struct Node));
                    curr->left->data = value;
                    curr->left->left = NULL;
                    curr->left->right = NULL;
                    return;    
                }
                curr = curr->left;
            }
            else
            {
                if(curr->right == NULL)
                {
                    curr->right = (struct Node*)malloc(sizeof(struct Node));
                    curr->right->data = value;
                    curr->right->left = NULL;
                    curr->right->right = NULL;
                    return;    
                }
                curr = curr->right;
            }
        }
    } 
        printf("%s", "Exeption");
}
void Clear(struct Node* root)
{
   if(root == NULL)
   {
      return;
   }
   Clear(root->left);
   Clear(root->right);
   free(root);
   
}

void showTree(const struct Node* root)
{
    if(root == NULL)
    {
        return;
    }
    showTree(root->left);
    printf("%d ", root->data);
    showTree(root->right);
}

int main()
{
    struct Node* root = createNode(1);
    insertNode(&root, 2); 
    insertNode(&root, 5); 
    insertNode(&root, -12); 
    showTree(root); 
    Clear(root); 

    return 0;
}
