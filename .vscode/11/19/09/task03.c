#include <stdio.h>
#include <stdlib.h>

struct dnode
{
  int data;
  struct dnode *next;
  struct dnode *prev;
};

struct dlinklist
{
   struct dnode *head;
   int length;
   
};
void dinsertafterlastnode(struct dlinklist *l , int x)
{
    
    struct dnode *newnode = malloc(sizeof(struct dnode));
    newnode->data = x;
    newnode->next=NULL;

    if(l->head == NULL)
    {
        newnode->next = l->head;
        l->head = newnode;
    }
    else
    {
        struct dnode *current = l->head;
        while(current->next !=  NULL)
        {
            current = current->next;
        
        }
        current->next = newnode;
        newnode->prev = current;
    };
    l->length++;
}

void forwarddisplay(struct dlinklist l)
{
   struct dnode *current = l.head;
   printf("Forward : ");
   while(current != NULL)
   {
    printf("%d ",current->data);
    current = current->next;
   }
   printf("\n");
}

void displaybackword(struct dlinklist l)
{
    if(l.head == NULL)
    {
        printf("Backward : (Empty)\n");
        return;
    }
    struct dnode *current = l.head;
    while (current->next != NULL)
    {
        current=current->next;
    }
    printf("Backward: ");
    while(current != NULL)
    {
        printf("%d ",current->data);
        current=current->prev;
    }
    printf("\n");  
}

void dinsertbeforehead(struct dlinklist *l , int x)
{
    struct dnode *newnode = malloc(sizeof(struct dnode));
    newnode->data = x;
    newnode->next= l->head;
    newnode->prev = NULL;

    if(l->head != NULL)
    {
        l->head->prev = newnode;      
    }
    l->head = newnode;
    l->length++;
}

void ddeletenode(struct dlinklist *l , int x)
{
  int index=0;
  struct dnode *current = l->head;
  while(current != NULL && current->data != x)
  {
    current = current->next;
    index++;
  }

  if(current == NULL)
  {
    printf("Key %d id not found.\n",x);
    return;
  }

  if (index == l->length / 2)                 
     printf("Deleting the middle value %d\n", x);
    
  if(current->prev != NULL)
  {
    current->prev->next = current->next;
  }
  else
  {
    l->head = current->next;
  }
  if(current->next != NULL)
  {
    current->next->prev = current->prev;
  }
  free(current);
  l->length--;
  printf("Delete %d \n",x);
}

void dinsertsorted(struct dlinklist *l, int x)
{
    /* Case 1: empty list, or x belongs before the head */
    if (l->head == NULL || x <= l->head->data)
    {
        dinsertbeforehead(l, x);
        return;
    }

    struct dnode *newnode = malloc(sizeof(struct dnode));
    if (newnode == NULL) return;
    newnode->data = x;

    /* Find the last node whose data is smaller than x */
    struct dnode *current = l->head;
    while (current->next != NULL && current->next->data < x)
        current = current->next;

    /* Case 2 and 3: insert after current (middle or tail) */
    newnode->next = current->next;
    newnode->prev = current;

    if (current->next != NULL)           
        current->next->prev = newnode;

    current->next = newnode;
    l->length++;
}

int main()
{
    struct dlinklist l;
    l.head = NULL;
    l.length = 0;
    dinsertbeforehead(&l , 400);
    dinsertafterlastnode(&l , 90);
    dinsertafterlastnode(&l , 60);
    dinsertafterlastnode(&l , 70);
    dinsertafterlastnode(&l , 40);


    forwarddisplay(l);
    displaybackword(l);
    ddeletenode(&l , 60);
    displaybackword(l);
    ddeletenode(&l , 100);
    displaybackword(l);

    return 0;
}