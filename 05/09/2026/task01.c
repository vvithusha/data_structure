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
    int length;
};
void insert(struct linklist *l, int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = data;
    newnode->next = NULL;

    if (l->head == NULL)
    {
        l->head = newnode;
    }
    else
    {
        struct node *temp = l->head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    l->length++;
}
void display(struct linklist l)
{
    struct node *temp = l.head;
    while(temp !=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("End \n");
}
void deleteitem(struct linklist *l,int data)
{
    struct listnode *scan1=l->head;
    if(scanf->data == data)
    {
        l->head=scan1->next;
        free(scan1);
        l->length--;
    }
    else
    {
        link *scan2=scan1->next;
        
    }
}
int main()
{
    return 0;
}