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
    struct node head;
    struct node secound;
    struct node third;
    struct node fourth;

    head.data = 10;
    head.next = &secound;

    secound.data = 20;
    secound.next = &third;

    third.data = 30;
    third.next = &fourth;

    fourth.data = 40;
    fourth.next = NULL;

    struct node *temp = &head;
    while(temp!=NULL)
    {
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}
