#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct BinarySearchTree BST;
struct BinarySearchTree
{
    int data;
    BST *left, *right;
}*root=NULL;

void insert(int x){
    BST *newnode=(BST*)malloc(sizeof(BST));
    
    if(newnode==NULL){
        printf("No Memory!\n");
    }
    else{ 
        newnode->data=x;
        newnode->left=NULL;
        newnode->right=NULL;

        BST *temp=root;
        
        if(temp==NULL){
            root=newnode;
        }
        else{
        while(temp!=NULL){
            if(newnode->data == temp->data){
                printf("value already exist!\n");
                break;
            }
            else if((newnode->data < temp->data) && (temp->left==NULL)){
                temp->left=newnode;
                break;
            }
            else if(newnode->data < temp->data){
                temp=temp->left;
            }
            else if((newnode->data > temp->data) && (temp->right==NULL)){
                temp->right=newnode;
                break;
            }
            else{
                temp=temp->right;
            }
        }
        }
    }
    
}

void inorder(BST *node)
{
    if (node != NULL)
    {
        inorder(node->left);
        printf("%d  ", node->data);
        inorder(node->right);
    }
}

void preorder(BST *node)
{
    if (node != NULL)
    {
        printf("%d  ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

void postorder(BST *node)
{
    if (node != NULL)
    {
        postorder(node->left);
        postorder(node->right);
        printf("%d  ", node->data);
    }
}

int main()
{
    int val;
    do{
        printf("\nEnter a value to insert or Enter 0 to exit :");
        scanf("%d",&val);
        if(val!=0){
            insert(val);
        }
    }while(val!=0);
    
    printf("\nPrinting Inorder traversal : ");
    inorder(root);

    printf("\nPrinting Preorder traversal : ");
    preorder(root);

    printf("\nPrinting Postorder traversal : ");
    postorder(root);
    
    return 0;
}