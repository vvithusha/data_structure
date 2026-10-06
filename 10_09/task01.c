#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct linkstack
{
   struct node *top;
};

void initlinkstack(struct linkstack *s)
{
    s->top = NULL;
}

bool isemptylinked(struct linkstack *s)
{
    return s->top == NULL;
}
void pushlinked(struct linkstack *s, int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = s->top;
    s->top = newnode;
}

int poplinked(struct linkstack *s)
{
    if(isemptylinked(s))
    {
        printf("Stack is Empty\n");
        return -1;
    }
    struct node *temp = s->top;
    int value = temp->data;
    s->top = s->top->next;
    free(temp);
    return value;
}


int main()
{
    struct linkstack s;
    initlinkstack(&s);
    pushlinked(&s,10);
    pushlinked(&s,20);
    pushlinked(&s,30);
    printf("Elements in the stack are:\n");
    while(!isemptylinked(&s))
    {
        printf("%d\n",poplinked(&s));
    }
    printf("IS Stack Empty : %s\n",isemptylinked(&s)?"Yes" : "No");
    return 0;
}