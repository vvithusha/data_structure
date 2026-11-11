#include <stdio.h>
#include <stdlib.h>
struct queuearray
{
   int *array;
   int capacity;
   int first;
   int firstfree;
   int length;
};

struct queuearray* initqueue(int capacity)
{
    struct queuearray *q=(struct queuearray *)malloc(sizeof(struct queuearray));
    q->array=(int *)malloc(sizeof(int)*capacity);
    q->capacity=capacity;
    q->first=0;
    q->firstfree=0;
    q->length=0;
    return q;
}

//is Empty and is Full functions
int isemptyqueue(struct queuearray *q)
{
    return q->length==0;
}
int isfullqueue(struct queuearray *q)
{
    return q->length==q->capacity;
}

//insert fuction
void enqueue(struct queuearray *q,int value)
{
    if(isfullqueue(q))
    {
        printf("queue is full\n");
        return;
    }
    q->array[q->firstfree]=value;
    q->firstfree=(q->firstfree+1)%q->capacity;
    q->length++;
}

//remove function
int dequeue(struct queuearray *q)
{
    if(isemptyqueue(q))
    {
        printf("queue is empty\n");
        return -1;
    }
    int value = q->array[q->first];
    q->first=(q->first+1)%q->capacity;
    q->length--;
    return value;
}
//getfront and length functions
int getfront(struct queuearray *q)
{
    if(isemptyqueue(q))
    {
        printf("queue is empty\n");
        return -1;
    }
    return q->array[q->first];
}
int lengthqueue(struct queuearray *q)
{
    return q->length;
}

//display function
void displayqueue(struct queuearray *q)
{
    if(isemptyqueue(q))
    {
        printf("queue is empty\n");
        return;
    }
    printf("Front -> ");
    if(q->firstfree > q->first)
    {
        for(int i=q->first; i<q->firstfree; i++)
        {
            printf("%d ", q->array[i]);
        }
    }
    else
    {
        for(int i=q->first; i<q->capacity; i++)
        {
            printf("%d ", q->array[i]);
        }
        for(int i=0; i<q->firstfree; i++)
        {
            printf("%d ", q->array[i]);
        }
    }
    printf(" <- Rear\n");
}


int main()
{
    int array[5] = {1, 2, 3, 4, 5};
    struct queuearray *q = initqueue(5);
    for(int i=0; i<5; i++)
    {
        enqueue(q, array[i]);
    }
    displayqueue(q);
    printf("Dequeued: %d\n", dequeue(q));
    displayqueue(q);
    printf("Front element: %d\n", getfront(q));
    printf("Queue length: %d\n", lengthqueue(q));

    return 0;
}