#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
{
    int id;
    char name[30];
    float marks;
};
int main()
{
    struct student *s=(struct student *)malloc(sizeof (struct student));

    if(s==NULL)
    {
        printf("memory allocation failed\n");
        return 1;
    }

    s->id=1;
    strcpy(s->name,"John Doe");
    s->marks=85.5;

    printf("student ID: %d\n",s->id);
    printf("student name : %s\n",s->name);
    printf("student marks : %.2f\n",s->marks);

    free(s);
    return 0;
}

