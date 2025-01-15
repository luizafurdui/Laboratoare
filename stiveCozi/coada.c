

#include <stdlib.h>
#include <stdio.h>

struct Queue {
    int size;
    int front;
    int rear;
    int* Q;
};

void create(struct Queue* q, int size)
{
    q->size = size;
    q->front = -1;
    q->rear = -1;
    q->Q = (int*)malloc(sizeof(int));

}

void enqueue(struct Queue* q, int val)
{
    if (q->front == q->size - 1)
        printf("coada este goala");
    else {
        if (q->front == -1) q->front = 0;
        q->rear++;
        q->Q[q->rear] = val;
    }

}

void Display(struct Queue* q)
{

    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->Q[i]);

    }

    printf("\n");


}
int dequeue(struct Queue * q)
{
    int x=-1;
    if(q->rear < q->front)
    {
        printf("coada este goala"); 
    }
    else
    {

        x = q->Q[q->front];  
        q->front++; 
        if(q->front > q->rear)
        {
            q->front = 0; 
            q->rear = -1; 
        }


    }
    return x; 
}
int main()
{
    struct Queue q;
    create(&q, 5);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    Display(&q);

    printf("%d ", dequeue(&q));
    return 0;
}