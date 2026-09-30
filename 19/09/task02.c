#include <stdio.h>
#include <stdlib.h>
struct cnode
{
    int data;
    struct cnode *next;
};

struct clinklist
{
    struct cnode *head;
    int length;
};

void insertlastnode(struct clinklist *l , int x)
{
    struct cnode *newnode = malloc(sizeof(struct cnode));

    newnode->data = x;
    if(l->head == NULL)
    {
        newnode->next = newnode;
        l->head = newnode;
    }
    else
    {
        struct cnode *current = l->head;
        while(current->next != l->head)
        {
            current=current->next;
        }
        current->next=newnode;
        newnode->next = l->head;
    }
    l->length++;
}

void diaply(struct clinklist l)
{
    if(l.head == NULL)
    {
        printf("Circular List : (Empty)\n");
        return ;
    }
    struct cnode *current=l.head;
    printf("Circular List : ");
    do{
        printf("%d ",current->data);
        current=current->next;
    }while(current != l.head);
    printf("back to head");
}


int main()
{
    struct clinklist l;
    l.head = NULL;
    l.length = 0;

    insertlastnode(&l , 10);
    insertlastnode(&l , 30);
    insertlastnode(&l , 60);
    insertlastnode(&l , 90);

    diaply(l);
    return 0;
}