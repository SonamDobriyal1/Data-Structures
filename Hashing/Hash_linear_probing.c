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
    while(hashtable[hashindex]!=-1){
        hashindex=(hashindex+1)%SIZE;
        if(hashindex==originalindex){
            printf("NO MORE PLACE TO INSERT\n");
            return;
        }
    }hashtable[hashindex]=x;
    printf("Value inserted\n");


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
   while(hashtable[index]!=x){
        index=(index+1)%SIZE;
        if(originalindex==index){
            printf("Cannot find\n");
            return;
        }


   }hashtable[index]=-1;
   printf("deleted successfully\n");
}

void search(int x){
    int index=hash(x);
    int originalindex=index;
   while(hashtable[index]!=x){
        index=(index+1)%SIZE;
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
    deletes(100);
    deletes(55);



    display();
    search(35);
    search(55);



}


