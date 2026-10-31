#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{
    struct node *node1 = (struct node *)malloc(sizeof(struct node));
    struct node *node2 = (struct node *)malloc(sizeof(struct node));
    struct node *node3 = (struct node *)malloc(sizeof(struct node));
    struct node *node4 = (struct node *)malloc(sizeof(struct node));

    struct node *nodes[4] = {node1, node2, node3, node4};
    for(int i=0 ; i<4 ; i++)
    {
        printf("Enter the data for node %d: ", i+1);
        scanf("%d", &nodes[i]->data);
    }
    
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=NULL;

    struct node *temp = node1;
    while(temp != NULL)
    {
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    free(node1);
    free(node2);
    free(node3);
    free(node4);
    
    return 0;
}