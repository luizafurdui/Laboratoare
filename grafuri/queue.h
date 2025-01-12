#ifndef QUEUE_H
#define QUEUE_H
#include <stdlib.h>
#include <stdio.h>
struct Node{
    int data; 
    struct Node * next; 
}*front =NULL, *rear=NULL;

void enqueue(int x)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    if(newNode == NULL ) printf("queue is full\n"); 
    else{
         newNode->data = x; 
         newNode->next = NULL; 
        if(front == NULL)
        {
            front=rear=newNode; 
        }
        else{
            rear->next = newNode; 
            rear = newNode; 
        }
    }
}

int dequeue()
{
    int x=-1; 
    struct Node *t; 
    if(front == NULL ) printf("Queue is empty\n"); 
    else{

        x = front->data; 
        t=front; 
        front = front->next; 
        free(t);
    }
    return x; 

}

int isEmpty()
{
    return front == NULL;
}

#endif