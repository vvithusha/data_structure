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

void cinsertafterlastnode(struct clinklist *l, int x)
{
    struct cnode *newnode = malloc(sizeof(struct cnode));
    if (newnode == NULL) return;
    newnode->data = x;
    newnode->next = NULL;

    if (l->head == NULL)
    {
        l->head = newnode;
        newnode->next = newnode;
    }
    else
    {
        struct cnode *current = l->head;
        while (current->next != l->head)
        {
            current = current->next;
        }
        current->next = newnode;
        newnode->next = l->head;
    }
    l->length++;
}

void display(struct clinklist l)
{
    if (l.head == NULL)
    {
        printf("Link list : (Empty)\n");
        return;
    }

    struct cnode *current = l.head;
    do
    {
        printf("%d ", current->data);
        current = current->next;
    } while (current != l.head);
    printf("\n");
}

int cCountNodes(struct clinklist L)
{
    if (L.head == NULL)
        return 0;

    int count = 0;
    struct cnode *current = L.head;

    do
    {
        count++;
        current = current->next;
    } while (current != L.head);

    return count;
}

void cfree(struct clinklist *l)
{
    if (l->head == NULL) return;
    struct cnode *current = l->head->next;
    while (current != l->head)
    {
        struct cnode *tmp = current;
        current = current->next;
        free(tmp);
    }
    free(l->head);
    l->head = NULL;
    l->length = 0;
}

int main()
{
    struct clinklist l;
    l.head = NULL;
    l.length = 0;

    cinsertafterlastnode(&l, 20);
    cinsertafterlastnode(&l, 50);
    cinsertafterlastnode(&l, 70);
    cinsertafterlastnode(&l, 90);
    cinsertafterlastnode(&l, 10);

    display(l);
    printf("Node count = %d\n", cCountNodes(l));

    cfree(&l);
    return 0;
}