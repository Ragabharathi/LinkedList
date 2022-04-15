
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void createNode(struct Node **head,int data){
    struct Node * newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    if(*head==NULL){
        *head=newNode;
    }
    else{
        struct Node *temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
}
void display(struct Node *head){
    if(head==NULL)
    printf("Empty");
    else{
        struct Node *temp=head;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}
void removeLoop(struct Node *loop,struct Node *head){
    struct Node *ptr1=loop,*ptr2=loop;
    int k=1;
    //count no of nodes in loop
    while(ptr2->next!=ptr1){
        k++;
        ptr2=ptr2->next;
    }
    ptr1=ptr2=head;
    //locate ptr2 after k nodes
    for(int i=0;i<k;i++){
        ptr2=ptr2->next;
    }
    //both pointor meet at starting point of loop
    while(ptr1!=ptr2){
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    //find ending point of loop
    while(ptr2->next!=ptr1){
        ptr2=ptr2->next;
    }
    // break the loop
    ptr2->next=NULL;
}
void loopDetection(struct Node *head){
    struct Node* fast=head,*slow=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast)
        {
            removeLoop(slow,head);
            break;
        }
    }
    
}
int main(){
    struct Node * head=NULL;
    int n=5,data;
    for(int i=0;i<n;i++){
        scanf("%d",&data);
        createNode(&head,data);
    }
    head->next->next->next->next->next=head->next->next;
    loopDetection(head);
    display(head);
    return 0;
}
