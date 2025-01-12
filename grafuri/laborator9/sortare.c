
#include <stdlib.h>
#include <stdio.h>
#include "lista.h"
void dfsForOrder(int i, struct Graph* graf, int visited[], int stack[], int *top)
{
    visited[i] = 1; 
    struct Node * temp = graf->liste[i]; 
    while(temp!=NULL)
    {
        int vecin = temp->val; 
        if(!visited[vecin])
        {
            dfsForOrder(vecin, graf, visited, stack, top); 
        }




        temp = temp->next; 
    }

    //adaug nodul in stiva dupa ce i am explorat toti vecinii 
    stack[(*top)++] = i;

}

void topologicalOrder(struct Graph* graf, int nrNoduri)
{
    int visited[101] = {0}; 
    int stack[101] = {0};
    int top = 0; 

    for(int i = 1; i<=nrNoduri; i++)
    {
        if(!visited[i])
        {
            dfsForOrder(i, graf, visited, stack, &top); 
        }
    }

       printf("Sortarea topologica: ");
    for (int i = top - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");

}