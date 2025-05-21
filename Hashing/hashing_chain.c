#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

struct node{
int data;
struct node *next;
};

typedef struct node *node;

node hashtable[SIZE];


int hash(int x){
return x%SIZE;
}

node createnode(int x){
    node temp;
    temp=(node)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    return temp;

}

void insert(int x){
    node temp;
    int index=hash(x);
    temp=createnode(x);
    temp->next=hashtable[index];
    hashtable[index]=temp;
}

void deletes(int x){
    int index=hash(x);
    node temp=hashtable[index],prev=NULL;
    while(temp!=NULL && temp->data!=x){
        prev=temp;
        temp=temp->next;
    }if(temp==NULL){
    printf("Element not found so can't delete\n");
    return;
    }if(prev==NULL){
        hashtable[index]=temp->next;
    }else{
        prev->next=temp->next;

    }
    free(temp);
    printf("Deletion Successful\n");

}

void search(int x){
    int index=hash(x);
    node temp=hashtable[index];
    while(temp!=NULL){
        if(temp->data==x){
                printf("ELEMENT FOUND\n");
                return;
    }temp=temp->next;
}printf("element not found\n");
}

void display(){
    for(int i=0;i<SIZE;i++){
        node temp=hashtable[i];
        if(temp!=NULL){
            printf("[%d]===>",i);
            while(temp!=NULL){
                printf(" %d-",temp->data);
                temp=temp->next;
            }printf("\n");
        }
    }
}

void main(){
    insert(10);
    insert(20);
    insert(13);
    insert(5);
    insert(55);
    insert(105);
    insert(5);
    display();
    search(55);
    search(5);
    search(100);
    deletes(5);
    deletes(13);
    display();
}

