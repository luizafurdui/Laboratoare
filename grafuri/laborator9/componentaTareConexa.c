
#include <stdlib.h>
#include <stdio.h>
#include "lista.h"
void printGraph2(struct Graph * graf, int nrNoduri)
{
    for(int i = 1; i<= nrNoduri; i++)
    {
        printf("[%d]:", i); 
        struct Node * temp = graf->liste[i]; 
        while(temp)
        {
            printf("%d ", temp->val); 
            temp = temp->next; 
            
        }
        printf("\n");

    }

}
void dfs2(struct Graph * grafTranspus, int node, int visited[])
{
    visited[node] = 1; 
    struct Node * temp = grafTranspus->liste[node];
    while(temp)
    {
        if(!visited[temp->val])
        {
            dfs2(grafTranspus, temp->val, visited); 
        }
        temp = temp ->next; 
    }

}
void dfs1(struct  Graph *graf, int i, int visited[], int stack[], int * top)
{
   visited[i] = 1;
    struct Node * temp = graf->liste[i]; 
    while(temp) 
    {
        if(!visited[temp->val])
        {
            dfs1(graf, temp->val, visited, stack, top); 
        }
        temp = temp->next; 
    }

    stack[(*top)++] = i; 
    

}
void componentaTareConexa(struct Graph * graf, int NrNoduri)
{
    //construiesc graful transpus. initalizez un graf nou
int nrComponente = 0; 
    struct Graph * tempGraf = createGraph(NrNoduri, graf->isDirected); 

    for(int i = 1; i<=NrNoduri; i++) 
    {
        struct Node * temp = graf->liste[i]; 
        while(temp) 
        {
           
            struct Node * newNode = createNode(i); 
            newNode->next = tempGraf->liste[temp->val]; 
            tempGraf->liste[temp->val] = newNode; 

           
            temp = temp->next ; 
        }

    }

   //printGraph2(tempGraf, NrNoduri);

   int visited[101] = {0}; 
   int stack[101], top=0; 
   for(int i = 1; i<=graf->NrNoduri; i++)
   {
    if(!visited[i])
    {
        dfs1(graf, i, visited, stack, &top); 
    }
   }

     for (int i = 1; i <= NrNoduri; i++) {
        visited[i] = 0;
    }

    printf("Componentele tare conexe sunt:\n");
    while(top>0)
    {
        int node = stack[--top]; 
        if(!visited[node])
        {
            dfs2(tempGraf, node, visited); 
            nrComponente++; 
            //am gasit o componenta tare conexa
        }
    }


printf("%d", nrComponente); 
}


