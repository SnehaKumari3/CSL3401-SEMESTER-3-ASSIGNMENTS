#include <stdio.h>
#include <stdlib.h>
typedef struct Node SLL;
struct Node{
    int data;
    SLL *next;
    SLL *first;
    
}*head = NULL;

int isEmpty(){
    if(head==NULL)
        return 1;
    else{
        return 0;
    }
}

void insert_End(int x){
    SLL *new_node;
    new_node=(SLL*)malloc(sizeof(SLL));
    if(new_node==NULL){
        printf("NO Memory available.\n");
    }
    else{
        new_node->data=x;
        new_node->next=NULL;
        if(isEmpty()){
            head=new_node;
            printf("node inserted at beggining.\n");
        }
        else{
            SLL *temp;
            temp=head;
            while(temp->next!=NULL){
                    temp=temp->next;
                }
                temp->next=new_node;
                new_node->first=temp;
                printf("Node created.\n");
            }
            
        
    }

}

void insert_Beginning(int x){
    SLL *new_node;
    new_node=(SLL*)malloc(sizeof(SLL));
    if(new_node==NULL){
        printf("NO Memory available.\n");
    }
    else{
        new_node->data=x;
        new_node->next=NULL;
        if(isEmpty()){
            head=new_node;
            printf("node inserted at beggining.\n");
        }
        else{
            new_node->next=head;
            head->first=new_node;
            head=new_node;
            printf("Node created.\n");
        }
    }
}

void insert_After_Node(int key,int x){
    SLL *new_node;
    new_node=(SLL*)malloc(sizeof(SLL));
    if(new_node==NULL){
        printf("NO Memory available.\n");
    }
    else{
        new_node->data=x;
        new_node->next=NULL;
        if(isEmpty()){
            printf("List Is Empty , Insertion is not possible.\n");
        }
        else{
            SLL *temp;
            temp=head;
            while(temp->next!=NULL && temp->data!=key){
                    temp=temp->next;
                }

                if(temp!=NULL){   
                     new_node->next=temp->next;
                     new_node->first=temp;
                     temp->next->first=new_node;
                     temp->next=new_node;
                     printf("Node created.\n");
                }
                else{
                    printf("Element not found!.\n");
                }
            }
            
    }
}


void deleteNode(int n){
    if(isEmpty()){
        printf("List is empty , nothing to delete\n");
    }
    else {
        SLL *temp=head;
        int x=-1;
        while(temp!=NULL){
            if(temp->data==n){
                if(temp==head){
                    x=temp->data;
                    temp->next->first=NULL;
                    head=temp->next;
                printf("node deleted (deleted element : %d )\n",x);
                }
                else if(temp->next==NULL){
                    temp->first->next=NULL;
                }
                else{
                    x=temp->data;
                    temp->first->next=temp->next;
                    temp->next->first=temp->first;
                    printf("node deleted (deleted element : %d )\n",x);
                }
                return;

            }
            temp=temp->next;
            
        }
        if(x==-1)
            printf("node not found\n");
        
    }
}

void displayList(){
    if(isEmpty()){
        printf("List is empty , nothing to display\n");
    }
    else{
        SLL *temp=head;
        while(temp!=NULL){
        printf("%d  ",temp->data);
        temp=temp->next;
    }
    printf("\n");
    }
}

void displayReverseList(){
    if(isEmpty()){
        printf("List is empty , nothing to display\n");
    }
    else{
        SLL *temp=head;
        while(temp->next!=NULL){
        temp=temp->next;
    }
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->first;
    }
    printf("\n");
    }
}


int main(){
    int value,option,key;

    do{

        printf("Select the opertaion you want to perform. Enter 0 to exit.\n");
        
        printf("1. insert_End()\n");
        printf("2. insert_Beginning()\n");
        printf("3. insert_After_Node()\n");
        printf("4. isEmpty()\n");
        printf("5. deleteNode()\n");
        printf("6. displayList()\n");
        printf("7. displayReverseList()\n");
        printf("8. clearscreen()\n");
        printf("Enter your choice: ");
        scanf("%d",&option);


        switch (option)
        {
        case 0:
            break;
        case 1:
            printf("enter the element you want to add to list: ");
            scanf("%d",&value);
            insert_End(value);
            break;
        case 2:
            printf("enter the element you want to add to list: ");
            scanf("%d",&value);
            insert_Beginning(value);
            break;
        case 3:
            printf("enter the element you want to add to list: ");
            scanf("%d",&value);
            
            printf("enter the element after which you want to add in the list: ");
            scanf("%d",&key);
            insert_After_Node(key,value);
            break;
        case 4:
            if(isEmpty()){
            printf("List is empty .\n");
            }
            else{
                printf("List is not empty .\n");
            }
            break;
        case 5:
            printf("enter the element you want to delete: ");
            scanf("%d",&value);
            deleteNode(value);
            break;
        case 6:
            displayList();
            break;
        case 7:
            displayReverseList();
            break;
        case 8:
            system("cls");
            break;
        default:
            printf("wrong input.\n");
            break;
        }

    }while(option!=0);

   
    return 0;
}