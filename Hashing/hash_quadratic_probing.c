#include <stdio.h>
#define SIZE 5
int hashtable[SIZE];
int hash(int x){
    return x%SIZE;
}

void insert(int x){
    int hashindex;
    hashindex=hash(x);
    int originalindex=hashindex;
    int i=0;
    while(hashtable[(hashindex+i*i)%SIZE]!=-1 && i<SIZE){
        i++;
    }if(i==SIZE){
        printf("No place to insert,hash table is full\n");
    }hashtable[(hashindex+i*i)%SIZE]=x;
    printf("Successfully inserted\n");




}

void display(){
    for(int i=0;i<SIZE;i++){
            if (hashtable[i]!=-1){
                printf("%d -- ",hashtable[i]);
            }
}printf("\n");
}

void deletes(int x){
    int index=hash(x);
    int originalindex=index;
    int i=0;
   while(hashtable[(index+i*i)%SIZE]!=x && i<SIZE){
        i++;
        if(originalindex==index){
            printf("Cannot find, So no deletion\n");
            return;
        }


   }hashtable[index]=-1;
   printf("deleted successfully\n");
}

void search(int x){
    int index=hash(x);
    int originalindex=index;
    int i=0;
   while(hashtable[(index+i*i)%SIZE]!=-1 && i<SIZE){
        i++;
        index=((index+i*i)%SIZE);
        if(originalindex==index){
            printf("Cannot find\n");
            return;
        }


   }if(hashtable[index]==x){
   printf("Element found\n");}
   else{
    printf("Not found");
   }


}

void main(){
   // int hashtable[SIZE];
    for(int i=0;i<SIZE;i++){
        hashtable[i]=-1;
    }
    printf("Element is going to be added\n");
    insert(10);
    insert(35);
    insert(49);
    insert(55);
    insert(100);
    display();
    deletes(10);
    deletes(55);



    display();
    search(35);
    search(55);



}


