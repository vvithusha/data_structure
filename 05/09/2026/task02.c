#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    int n,value;
    printf("Enter the number of node:");
    scanf("%d",&n);

    struct node *head =NULL , *tail = NULL;

    for(int i=0 ; i<n ;i++)
    {
        printf("Enter the value for node %d :",i+1);
        scanf("%d",&value);

        struct node *newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data = value;
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }

    struct node *current = head;
    while(current !=NULL)
    {
        struct node *temp=current;
        current = current->next ; 
        free(temp);
    }

    }
    return 0;
}
