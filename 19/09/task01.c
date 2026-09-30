#include <stdio.h>
#include <stdlib.h>

struct dnode {
    int data;
    struct dnode *prev;
    struct dnode *next;
};

struct dlinklist {
    struct dnode *head;
    int length;
};

void indsertbeforehead(struct dlinklist *l, int x)
{
    struct dnode *newnode = malloc(sizeof(struct dnode));
    if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    newnode->data = x;
    newnode->prev = NULL;
    newnode->next = l->head;

    if (l->head != NULL)
        l->head->prev = newnode;

    l->head = newnode;
    l->length++;
}

void insertafterlastnode(struct dlinklist *l, int x)
{
    struct dnode *newnode = malloc(sizeof(struct dnode));
    if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    newnode->data = x;
    newnode->next = NULL;

    if (l->head == NULL)
    {
        newnode->prev = NULL;
        l->head = newnode;
    }
    else
    {
        struct dnode *current = l->head;
        while (current->next != NULL)
            current = current->next;

        current->next = newnode;
        newnode->prev = current;
    }
    l->length++;
}

void ddisplayforward(struct dlinklist l)
{
    struct dnode *current = l.head;
    printf("Forward : ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void deisplaybackword(struct dlinklist l)
{
    if (l.head == NULL)
    {
        printf("Backward : (Empty)\n");
        return;
    }
    struct dnode *current = l.head;
    while (current->next != NULL)
        current = current->next;

    printf("Backward : ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

void delete (struct dlinklist *l , int key)
{
    struct dnode *current = l->head;
    while(current!=NULL && current->data != key)
    {
        current=current->next;
    }
    if(current == NULL)
    {
        printf("key %d is not found ",key);
        return;
    }
    if(current->prev != NULL)
    {
        current->prev->next = current->next;
    }
    else
    {
        l->head=current->next;
    }

    if(current->next != NULL)
    {
        current->next->prev = current->prev;
    }
    free(current);
    l->length--;
    printf("Delete %d \n",key);
}

void freelist(struct dlinklist *l)
{
    struct dnode *current = l->head;
    while (current != NULL)
    {
        struct dnode *next = current->next;
        free(current);
        current = next;
    }
    l->head = NULL;
    l->length = 0;
}

int main()
{
    struct dlinklist l;
    l.head = NULL;
    l.length = 0;

    indsertbeforehead(&l, 10);
    indsertbeforehead(&l, 5);
    insertafterlastnode(&l, 20);
    insertafterlastnode(&l, 30);

    ddisplayforward(l);
    deisplaybackword(l);

    freelist(&l);
    return 0;
}