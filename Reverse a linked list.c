#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void createList(struct Node **head,int x){
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=x;
    newnode->next=NULL;
    if(*head==NULL)
    *head=newnode;
    else{
        struct Node *temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void display(struct Node *head){
    if(head==NULL)
    printf("Empty");
    else{
        while(head!=NULL){
            printf("%d ",head->data);
            head=head->next;
        }
    }
}
struct Node *reverseList(struct Node *head){
    struct Node *cur=head;
    struct Node *next=NULL;
    struct Node *prev=NULL;
    while(cur!=NULL){
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    head=prev;
    return head;
}
int main()
{
   int n;
   scanf("%d",&n);
   struct Node *head=NULL;
   int x;
   for(int i=0;i<n;i++){
       scanf("%d",&x);
       createList(&head,x);
   }
   head=reverseList(head);
   display(head);
    return 0;
}
