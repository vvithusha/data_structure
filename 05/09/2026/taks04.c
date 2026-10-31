#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
{
  int id;
  char name[30];
  float gpa;
};

struct node
{
   struct student data;
   struct node *next;
};

struct studentlist
{
    struct node *head;
    int length;
};

struct node* createstudentnode(int id , char name[] , float gpa)
{
    struct node *newnode = (struct node *) malloc(sizeof(struct node));

    if(newnode == NULL)
    {
        printf("memory allocation failed.\n");
    }

    newnode->data.id =id;
    newnode->data.gpa = gpa;
    strcpy(newnode->data.name,name);

    newnode->next=NULL;

    return newnode;
}

void indertatend(struct studentlist *l,int id,char name[],float gpa)
{
    struct node *newnode = createstudentnode(id,name,gpa);

    if(l->head == NULL)
    {
        l->head = newnode;
    }
    else
    {
        struct node *current = l->head;
        while(current->next != NULL)
        {
                current = current->next;
        }
        current->next=newnode;
    }
    l->length++;
}

struct node* serchbyid(struct studentlist *l,int id)
{
    struct node *current = l->head;

    while(current != NULL)
    {
        if(current->data.id == id)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void deletebyid(struct studentlist *l , int id)
{
    struct node *current = l->head;
    struct node *previous = NULL;
 
    while(current != NULL && current->data.id != id)
    {
        previous = current;
        current = current->next;
    }
    if(current == NULL)
    {
        printf("Student with id %d not found.\n", id);
        return;
    }
    if(previous == NULL)
    {
        l->head = current->next;

    }
    else
    {
        previous->next = current->next;
    }
    free(current);
    l->length--;
}

void displaylist(struct studentlist *l)
{
    struct node *current = l->head;

    if(current == NULL)
    {
        printf("empty list.\n");
    }
    else
    {
        while(current !=NULL)
        {
            printf("ID : %d , NAME : %s , GPA : %.1f \n",
            current->data.id , current->data.name, current->data.gpa );
            current = current->next;
        }
    }
}
int main()
{
    struct studentlist *l= malloc(sizeof(struct studentlist));
    l->head = NULL;
    l->length = 0;

    //add 4 students detials
    indertatend(l ,101 ,"vithu" , 3.7);
    indertatend(l ,102 ,"balaa" , 4.0);
    indertatend(l ,103 ,"rajaa" , 3.9);
    indertatend(l ,104 ,"thash" , 3.8);

    //display list
    printf("\n************Initial List **************\n");
    displaylist(l);

    //found ID
    struct node *found = serchbyid(l,101);
    if(found != NULL)
    {
        printf("\nFound ID : %d , NAME : %s , GPA : %.1f \n",
            found->data.id,found->data.name,found->data.gpa);
    }

    //NOT found ID
    struct node *notfoundid = serchbyid(l,105);
    if(notfoundid == NULL)
    {
        printf("Student with id 105 not found.\n");
    } 

    //delete one detials
    printf("\n*****Deleting student 103******\n");
    deletebyid(l,103);

    //list after deletion
    printf("\n********List after deletions************\n");
    displaylist(l);
    return 0;
}