
#include <stdlib.h>
#include <stdio.h>
#include "lista.h"
#include "sortare.c"
#include "componentaTareConexa.c"


void addEdge(struct Graph * graf, int source, int dest)
{
    struct Node* newNode = createNode(dest);
    newNode->next = graf->liste[source]; 
    graf->liste[source] = newNode; 

    //daca graful e neorientat leg si destinatia de sursa
    if (!graf->isDirected)
    {
        newNode = createNode(source); 
        newNode->next = graf->liste[dest];
        graf->liste[dest] = newNode; 

    }
}

void printGraph(struct Graph* graf) {
    for (int i = 1; i <= graf->NrNoduri; i++) { 
        struct Node* temp = graf->liste[i];
        printf("[%d]: ", i);
        if (!temp) {
            printf("Nu are vecini.\n");
            continue;
        }
        while (temp) {
            printf("%d ", temp->val);
            temp = temp->next;
        }
        printf("\n");
    }
}

void dfsVisit(struct Graph * graf, int start, int visited[])
{
    visited[start] = 1; 
    struct Node* vecin = graf->liste[start]; 
    printf("%d ", start); 

    while (vecin) 
    {
        if (!visited[vecin->val])
        {
            visited[vecin->val] = 1; 
            dfsVisit(graf, vecin->val, visited); 
        }

        vecin = vecin->next; //parcurg toti vecinii 

    }


}
void dfs(struct Graph* graf)
{
    int visited[101] = { 0 }; 
    for (int i = 1; i <= graf->NrNoduri; i++) {
    if (!visited[i]) {
        dfsVisit(graf, i, visited);
    }
}

}

void bfsVisit(struct Graph* graf, int start, int visited[])
{

    struct Queue* q1 = createQueue(); 

    enqueue(q1, start); 
    int i; 
    visited[start] = 1; 
  
    while (!isEmpty(q1))
    {
        i = dequeue(q1); 
        printf("%d ", i);

        struct Node* vecin = graf->liste[i]; 
        while (vecin)
        {
            if (!visited[vecin->val]) //daca vecinul nu este in coada
            {
                enqueue(q1,vecin->val); //il adaug in coada
                visited[vecin->val] = 1; //il marchez ca vizitat 
            }
            vecin = vecin->next; 
        }                  
    }
}
bfs(struct Graph * graf){
    int visited[101] = {0};  
    for(int i = 1; i<= graf->NrNoduri; i++)
    {
        if(visited[i] == 0)
        bfsVisit(graf, i, visited); 
    }

}
void shortestPath(struct Graph* graf, int start, int end)
{
    int i; 
    struct Queue * q2 = createQueue(); 
    enqueue(q2, start); 

    int visited[101] = {0}; 
    int parent[101] = {-1}; 
    visited[start] = 1; 


    while(!isEmpty(q2))
    {
        i = dequeue(q2); 
        if(i==end) break;

        struct Node * temp = graf->liste[i]; 
        while(temp)
        {
            if(visited[temp->val] == 0)
            {
                enqueue(q2, temp->val); 
                visited[temp->val] = 1; 
                parent[temp->val] = i;
            }
            temp = temp ->next; 
        }

    }


    if(!visited[end]) // nu s a ajuns la nodul final 
    {
        printf("nu exista cale"); 
    }
    else{
        int path[101]; 
        int pathLength = 0; 
        for(int j = end; j!= -1; j=parent[j])
        {
            path[pathLength++] = j;  
        }

         printf("Cea mai scurta cale de la %d la %d este: ", start, end);
         for(int j= pathLength-1; j>=0; j--)
         {
             printf("%d ", path[j]);
         }
                 printf("\n");


    }
}
int main()
{
    int NrNoduri = 6; 
    int isDirected = 1; 
    struct Graph* graf = createGraph(NrNoduri, isDirected); 
addEdge(graf, 1, 2);
addEdge(graf, 2, 3);
addEdge(graf, 3, 1);
addEdge(graf, 4, 5);
addEdge(graf, 5, 6);
addEdge(graf, 6, 4);
    printGraph(graf); 

    printf("\n"); 
    printf("DFS:"); 
    dfs(graf); 



    printf("\n");
    printf("BFS:");
    bfs(graf);

    printf("\n");


   shortestPath(graf, 6,5); 
    printf("\n");


    topologicalOrder(graf, NrNoduri);
    componentaTareConexa(graf, NrNoduri); 

  



    


    return 0; 
}

