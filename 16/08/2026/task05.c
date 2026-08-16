#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student
{
    int id;
    char *name;
};

int main()
{
    struct student *s=(struct student *)malloc(sizeof(struct student));
    
    
    return 0;
}
