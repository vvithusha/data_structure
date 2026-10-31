#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct linklist 
{
    struct node *head;
    int size;
};

void insiallist(struct linklist *l)
{
    l->head = NULL;
    l->size = 0;
};

//inset before head
void inserbeforehead(struct linklist *l , int x)
{
   struct node *newnode = malloc(sizeof(struct node));
   newnode->data = x;
   newnode->next = l->head;
   l->head = newnode;
   l->size++;
}

//insert after last node
void insertafternode(struct linklist *l ,int x)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;

    if(l->head == NULL)
    {
        l->head = newnode;    

    }
    else
    {
        struct node *current = l->head;
        while(current->next !=NULL)
        {
            current=current->next;
        }
        current->next = newnode;

    }
    l->size++;
}

//deletions

int main()
{

   // printf("%d",insiallist())
    return 0;
}