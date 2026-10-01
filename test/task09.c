#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if(n<=0 )
    {
        printf("Invalid number of nodes\n");
        return 1;
    }
    else
    {
    for(int i=0 ; i<n ;i++)
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));

        if(newnode == NULL)
        {
            printf("memory allocation is failed\n");
            return 1;
        }

        
    }
}
    return 0;
}