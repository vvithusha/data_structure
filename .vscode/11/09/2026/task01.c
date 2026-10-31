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
//insert after lastnode 
void insertafterlastnode(struct dlinklist *l , int x)
{
    struct dnode *newnode = malloc(sizeof(struct dnode));
    newnode->data = x;
    newnode->next = NULL;

    if(l->head == NULL)
    {
        newnode->prev = NULL;
        l->head = newnode;
    }
    else
    {
        struct dnode *current = l->head;
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = newnode;
        current->prev = current;
    }
    l->length++;
}

//forward double link list 
void dforward(struct dlinklist l)
{
    struct dnode *current = l.head;
    printf("Forward : ");
    if (current == NULL) {
        printf("(empty)\n");
        return;
    }
    while(current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
int main()
{
    struct dlinklist list;
    list.head = NULL;
    list.length = 0;

    insertafterlastnode(&list, 10);
    insertafterlastnode(&list, 20);
    insertafterlastnode(&list, 30);

    insertbeforehead(&list, 5);

    dforward(list);   // note: dforward takes the struct by value, not a pointer

    printf("Length: %d\n", list.length);

    return 0;
}