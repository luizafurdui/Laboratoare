
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
int visited[10];
void bfs(int m[][7], int start, int n)
{
    int i = start;
    // struct Queue* q; 
    int visited[7] = { 0 };

    printf("%d ", i);
    visited[i] = 1;
    enqueue(i);
    while (!isEmpty())
    {
        i = dequeue();
        for (int j = 1; j < n; j++)
        {
            if (m[i][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(j);
            }

        }
    }
}

void dfs(int g[][10], int start, int n)
{
    visited[start] = 1;
    printf("%d ", start);

    for (int i = 0; i < n; i++)
    {
        if (g[start][i] == 1 && visited[i] == 0)
        {
            dfs(g, i, n);
        }
    }
}
int main() {

    int m[10][10] = {
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // Linia 0 (ignorat)
       {0, 0, 0, 0, 1, 0, 1, 0, 0, 0}, // Nodul 1
       {0, 1, 0, 1, 0, 0, 0, 0, 0, 0}, // Nodul 2
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // Nodul 3
       {0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, // Nodul 4
       {0, 0, 1, 0, 0, 0, 0, 1, 0, 0}, // Nodul 5
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // Nodul 6
       {0, 0, 0, 0, 0, 0, 0, 0, 1, 1}, // Nodul 7
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // Nodul 8
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}  // Nodul 9
    };


    dfs(m, 5, 10);
    return 0;
}