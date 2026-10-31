#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    struct student 
    {
        int id;
        char name[30];
        float marks;
    };

    struct student s1[2];
    s1[0].id = 102;
    strcpy(s1[0].name,"vithi");

    printf("id : %d , name : %s\n",s1[0].id,s1[0].name);
    
    return 0;
}