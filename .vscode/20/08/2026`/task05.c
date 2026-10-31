#include <stdio.h>

struct node{
    int data;
    struct node *next;
};
int main()
{
    struct node node1,node2,node3;

    node1.data=10;
    node2.data=20;
    node3.data=30;

    node1.next = &node2;
    node2.next = &node3;
    node3.next = NULL;

    struct node *current = &node1;

    while(current != NULL)
    {
        printf("%d -> ",current->data);
        current = current->next;
    }
    printf("NULL\n");
    return 0;
}