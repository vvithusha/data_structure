#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node* insertAtBeginning(struct node *head , int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = value;
    newnode->next = head;
    head = newnode;
    return head;
}

struct node* insertAtEnd(struct node *head , int value )
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = value;
    newnode->next = NULL;

    if(head==NULL)
    {
        return head;
    }
    struct node *temp = head;
    while(temp->next !=NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    return head;
}

struct node* insertAtGivenPosition(struct node *head , int pos , int value)
{
    if(pos == 0 )
       return insertAtBeginning(head , value);

    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data;
    
    struct node *temp = head;
    for(int i= 0; i<pos-1 && temp != NULL ; i++)
    {
        temp = temp ->next;
    }
    if(temp == NULL)
    {
        printf("Invalid Position\n");
        free(newnode);
        return head;
    }

    newnode->next = temp->next;
    temp->next = newnode;
    return head;
}

struct node* deletefrombeginning(struct node *head)
{
    if(head == NULL)
    {
        printf("List is Empty!\n");
        return head;
    }

    struct node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct node* deleteEnd(struct node *head)
{
    if(head == NULL)
    {
        printf("List is Empty!\n");
        return  head;
    }
    if(head->next = NULL)
    {
        free(head);
        return NULL;
    }

    struct node *temp = head;
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

struct node* deleteposition(struct node *head , int pos)
{
    if(head == NULL)
    {
        printf("List is Empty!");
        return head;
    }
    if(pos ==0 )
    {
        return deletefrombeginning(head);
    }

    struct node *temp = head;
    for(int i= 0 ;i<pos-1 ; i++)
    {
        temp = temp->next;
    }

    if(temp->next == NULL)
    {
        printf("Invalid position\n");
        return head;
    }

    struct node *delete = temp->next;
    temp->next = delete->next ; 
    free(delete);
    return head;
}

void traversal(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int postion(struct node *head , int key)
{
    struct node *temp = head;
    int pos=0;
    while(temp != NULL)
    {
        if(temp->data == key)
        {
            return pos;
        }
        temp = temp->next;
        pos++;
    }
    return -1;
}


int main()
{
    struct node n1;
    n1.data = 90 ; 
    n1.next = NULL;
    insertAtBeginning(&n1 , 90);
    return 0;
}

