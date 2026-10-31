#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node* insertasbegining(struct node *head , int value)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = head;
    head = newnode;
    return head;
}

struct node* insertend(struct node *head ,int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if(head == NULL)
    {
        head = newnode;
        return head;
    }

    struct node *temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    return head;
}

struct node* insertposition(struct node *head, int value, int pos)
{
    if(pos == 0)
    {
        printf("invalid position\n");
    }
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    struct node *temp = head;
    for(int i=0 ; i<pos-1 ; i++)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("invalid position\n");
        free(newnode);
        return head;
    }

    newnode->next = temp->next;
    temp->next = newnode;
    return head;
}

struct node* deletefrombegining(struct node *head)
{
    if(head == NULL)
    {
        printf("list is empty\n");
        return NULL;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct node* deletefromend(struct node *head)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }

    if(head->next == NULL)
    {
        free(head);
        return NULL;
    }

    struct node *temp = head;
    while(temp->next->next == NULL)
    {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
    return head;

}

struct node* deleteposition(struct node *head , int pos)
{
    if(pos == 0)
    {
      return deletefrombegining(head);
    }

    struct node *temp = head;
    for(int i= 0 ; i<pos-1 && temp->next != NULL ; i++)
    {
        temp = temp->next;
    }

    if(temp->next == NULL)
    {
        printf("invalid position\n");
        return head;
    }

    struct node *todelete = temp->next;
    temp->next = todelete->next;
    free(todelete);
    return head;
}
int main()
{
    return 0;
}