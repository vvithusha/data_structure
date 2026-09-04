#include <stdio.h>
#include <stdlib.h>
struct student
{
    int id;
    float marks;
};
int main()
{
    int n=3;
    struct student *list=(struct student *)malloc(n*sizeof(struct student));
    if(list==NULL)
    {
        printf("memory allocation failed\n");
        return 1;
    }
    for(int i=0 ; i<n ;i++)
    {
        list[i].id=i+1;
        list[i].marks=60.0+i*10.0;

    }
    for(int i=0 ; i<n ; i++)
    {
        printf("student %d:marks = %.1f\n",list[i].id,list[i].marks);

    }
    free(list);
    return 0;
}
