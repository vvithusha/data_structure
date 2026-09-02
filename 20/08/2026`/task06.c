#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int data;
    struct node *next;
};

int main()
{
struct node *head = (struct node *)malloc(sizeof(struct node));
struct node *secound=(struct node *)malloc(sizeof(struct node));
struct node *thirt=(struct node *)malloc(sizeof(struct node));

if(head==NULL || secound==NULL ||thirt == NULL)
{
    printf("memory allocation is failed!/n");
    free(head);
    free(secound);
    free(thirt);
    return 0;
}

  head->data=5;
}