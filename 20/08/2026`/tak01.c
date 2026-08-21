#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
{
    int id;
    char name[50];
    float marks;
};
int main()
{
   struct student *s1 = (struct student *) malloc(sizeof (struct student));

   if(s1==NULL)
   {
    printf("memory allocation is failed\n");
   }
   else
   {
     s1->id = 101;
     strcpy(s1->name,"vithu");
     s1->marks = 80.9;

     printf("ID : %d\n",s1->id);
     printf("Name : %s\n",s1->name);
     printf("Marks : %.2f\n",s1->marks);

     free(s1);
   }
   return 0;
}