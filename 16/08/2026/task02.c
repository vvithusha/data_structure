#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    struct student 
    {
        int id;
        char *name;
        float marks;
    }s1,s2;

    student s1={101,'vithu',99.5};
    
    return 0;
}