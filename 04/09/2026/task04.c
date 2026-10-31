#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{
    struct node *head=(struct node *)malloc(sizeof(struct node));
    struct node *secound=(struct node *)malloc(sizeof(struct node));
    struct node *third =(struct node *)malloc(sizeof(struct node));

    head->data=10;
    head->next=secound;

    secound->data=20;
    secound->next=third;

    third->data=30;
    third->next=NULL;

    struct node *current = head;
    while(current !=NULL)
    {
        printf("%d ->",current->data);
        current= current->next;
    }
    printf("NULL\n");
    return 0;
}