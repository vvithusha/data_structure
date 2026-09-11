#include <stdio.h>
#include <stdlib.h>
struct dnode
{
    int data;
    struct dnode *prev;
    struct dnode *next;
};

struct dlinklist 
{
    struct dnode *head;
    int length;
};

void insertbeforehead(struct dlinklist *l , int x)
{
    struct dnode *newnode = malloc(sizeof(struct dnode));
    newnode->data = x;
    newnode->next = l->head;
    newnode->prev = NULL;

    if(l->head !=NULL)
    {
        l->head->prev = newnode;
    }
    l->head = newnode;
    l->length++;
}
int main()
{
    return 0;
}