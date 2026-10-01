#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node* inseratbegining(struct node *head , int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = head;
    newnode->prev = NULL;

    if(head != NULL)
    {
        head->prev = newnode;
    }
    return newnode;
}
struct node* insertatend(struct node *head, int value)
{
    struct node *newnode = (struct node *)malloc(Sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if(head == NULL)
    {
        newnode->prev = NULL;
        return newnode;
    }
    
    struct node *temp =head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
    return head;
}

struct node* insertposition(struct node *head,int value , int pos)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = NULL;

    if(pos == 0)
    {
        return inseratbegining(head , value);
    }

    struct node *temp = head;
    for(int i=0 ;i<pos-1 && temp != NULL ; i++)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("invalid position\n");
        free(newnode);
        return head;
    }

    struct node *nextnode = (struct node *)malloc(sizeof(struct node));
    nextnode->data = value;
    nextnode->next = temp->next;
    nextnode->prev = temp;

    if(temp->next != NULL)
    {
        temp->next->prev = nextnode;  
    }

    temp->next = nextnode;
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
    if(head != NULL)
    {
        head->prev = NULL;
    }
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
    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);
    return head;
}

struct node* deleteposition(struct node *head, int pos)
{
    if(pos == 0)
    {
        return deletefrombegining(head);
    }

    struct node *temp = head;
    for(int i=0 ; i<pos && temp != NULL ; i++)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("invalid position\n");
        return head;
    }

    if(temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    if(temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    
    free(temp);
    return head;
    }

int main()
{
    return 0;
}