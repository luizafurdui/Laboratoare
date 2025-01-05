
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data; 
    struct Node *next; 
};

struct List{
    struct Node * head; 
    struct Node * tail; 
}; 
struct List* createList()
{
    struct List* newList = (struct List*)malloc(sizeof(struct List)); 
    newList->head = NULL; 
    newList->tail = NULL; 
    return newList;  
}
struct Node* createNode(int val)
{
    struct Node * newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->data = val; 
    newNode->next = NULL; 
    return newNode; 

}
void insert(struct List *h, int x) // inserare la inceput si sfarsit
{

    struct Node * t; 
    t = createNode(x); 

    if(h->head == NULL) //lista e goala
    {
        h->head = t; 
        h->tail = t; 

    }
    else //lista nu e goala is adaug in coada
    {

        h->tail->next = t; 
        h->tail = t; 

    }
     

}

void displayList(struct List* list)
{

    struct Node * current = list->head; 
    while(current!= NULL )
    {
        printf("%d ", current->data);
        current = current->next;  

    }

}

int hash(int val, int size)
{
    return val%10; 
}
int main()
{

    int size = 10; 
    struct List* HT[10]; 

    for(int i=0; i<10; i++)
    {
       HT[i] = createList();     
    }

    insert(HT[(hash(12,size))], 12); 
    insert(HT[(hash(22,size))], 22); 
    insert(HT[(hash(32,size))], 32); 
    insert(HT[(hash(41,size))], 41); 

    for(int i = 0; i<10; i++)
    {
        printf("HT[%d]: ", i); 
        displayList(HT[i]); 
        printf("\n"); 
    }
  //  struct Node * temp = search(HT[hash(12, size)], 12); 
    return 0; 
}