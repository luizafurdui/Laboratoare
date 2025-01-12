
#ifndef LISTA_H
#define LISTA_H
#include <stdlib.h>
#include <stdio.h>

struct Node {
	int val; 
	struct Node *next; 
	//struct Node* prev; 

};
struct Queue{
    struct Node* rear; 
    struct  Node * front; 
};
struct Graph {
	int NrNoduri;
	int isDirected; 
	struct Node** liste; 
	
};

struct Queue* createQueue()
{
    struct Queue * queue = (struct Queue*)malloc(sizeof(struct Queue)); 
    queue->front = NULL; 
    queue->rear = NULL; 
    return queue; 

}
struct Node* createNode(int val)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if (!newNode) {
		printf("Eroare: Alocarea memoriei pentru nod a eșuat.\n");
		exit(EXIT_FAILURE); // Opțional: poți returna NULL în loc să oprești programul
	}
	newNode->next = NULL;
	newNode->val = val;
	return newNode;
}

void enqueue(struct Queue* q, int x)
{
	struct Node* newNode = createNode(x); 
	if (newNode == NULL)
	{
		printf("queue is full"); 
	}
	else
	{
		if (q->front == NULL) //coada e goala
		{
			q->front = newNode; 
			q->rear = newNode;

		}
		else
		{
			q->rear->next = newNode; 
			q->rear = newNode; 
		}
	}
}

int  dequeue(struct Queue * q)
{
	int x = -1;
	struct Node* temp;
	if (q->front == NULL)
	{
		printf("queue is empty"); 
	}
	else
	{		 		
		temp = q->front; 
		x = q->front->val; 
		q->front = q->front->next; 
		free(temp); 
	}
	return x; 
}

int  isEmpty(struct Queue * q)
{
	return q->front == NULL; 

}
struct Graph* createGraph(int NrNoduri, int isDirected)
{
	struct Graph* graf = (struct Graph*)malloc(sizeof(struct Graph));


	graf->NrNoduri = NrNoduri;
	graf->isDirected = isDirected;

	graf->liste = (struct Node**)malloc((NrNoduri + 1) * sizeof(struct Node*));

	for (int i = 1; i <= NrNoduri; i++) {
		graf->liste[i] = NULL;
	}

	return graf;
}





#endif
