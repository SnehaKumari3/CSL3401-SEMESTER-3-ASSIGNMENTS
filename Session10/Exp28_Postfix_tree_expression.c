#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node SLL;

struct Node
{
    char data;
    SLL *x;
    SLL *left;
    SLL *right;

}*head = NULL;;

int is_stackEmpty()
{
    if (head == NULL)
        return 1;
    else
    {
        return 0;
    }
}


int isOperator(char ch)
{
    if (ch=='+'||ch=='-'||ch=='*'||ch=='/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


SLL * pop_stack()
{
    if (is_stackEmpty)
    {
        printf("Stack is empty , nothing to pop\n");
    }
    else if (head->right == NULL)
    {
        SLL *temp=head;
        head = NULL;
        return temp;
    }
    else
    {
        SLL *temp = head;
        SLL *prev;
        prev = temp;
        while (temp->right != NULL)
        {
            prev = temp;
            temp = temp->right;
        }
        return temp;
        prev->right = NULL;
    }
}

void push_stack(char x)
{
    
    SLL *new_node_stack;
    new_node_stack = (SLL *)malloc(sizeof(SLL));
    
    SLL *new_node;
    new_node = (SLL *)malloc(sizeof(SLL));
    if (new_node_stack == NULL || new_node==NULL)
    {
        printf("NO Memory available.\n");
    }
    else
    {
        if(isOperator(x)){
            new_node->data = x;
            new_node->right=pop_stack();
            new_node->left=pop_stack();
        }
        else{
            new_node->data = x;
            new_node->right=NULL;
            new_node->left=NULL;

        }
        new_node_stack->right=NULL;
        new_node_stack->x=NULL;

        if (is_stackEmpty)
        {
            head = new_node_stack;
            new_node_stack->x=new_node;
            
        }
        else
        {
            SLL *temp;
            temp = head;
            while (temp->right != NULL)
            {
                temp = temp->right;
            }
            temp->right = new_node_stack;
            new_node_stack=new_node;
            
        }
    }
}

void Inorder(SLL *root){

    if(root!=NULL){
        Inorder(root->left);
        printf("%c  ",root->data);
        Inorder(root->right);
    }
}


void Preorder(SLL *root){
    

    if(root!=NULL){
        printf("%c  ",root->data);
        Inorder(root->left);
        Inorder(root->right);
    }
}

void Postorder(SLL *root){
    

    if(root!=NULL){
        
        Inorder(root->left);
        Inorder(root->right);
        printf("%c  ",root->data);
    }
}

int main(){
    char a[20];
    int l=0;
    printf("enter a postfix expression: ");
    gets(a);
    l=strlen(a);

    for(int i=0;i<l;i++){
        push_stack(a[i]);
    }

    printf(" Printing Inorder Traversal: ");
    Inorder(head);

    
    printf(" Printing Preorder Traversal: ");
    Preorder(head);

    
    printf(" Printing Postorder Traversal: ");
    Postorder(head);
    return 0;
}



