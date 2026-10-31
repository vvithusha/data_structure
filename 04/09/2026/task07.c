#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
{
    char name[50];
    int age;
    float marks;
};
int main()
{
    struct student *s1=(struct student *)malloc(5*sizeof(struct student));

    if(s1==NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    for(int i=0 ; i<5 ; i++)
    {
        s1[i].age = 18+i;
        sprintf(s1[i].name,"student %d",i+1);
        s1[i].marks = 20*i;
    }

    for(int i=0 ; i<5 ; i++)
    {
        printf("Name : %s, Age : %d, Marks : %.2f\n", s1[i].name, s1[i].age, s1[i].marks);
    }
    free(s1);
    return 0;
}