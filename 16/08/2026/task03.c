#include <stdio.h>
#include <string.h>
    struct student
    {
        /* data */
        int id;
        char *name;
    }s1;

int main()
{
    struct student students[2];
   
    s1.id=103;
    s1.name="saraa";
    
    students[0].id = 101;
    students[0].name="vithu";

    students[1].id=102;
    students[1].name="saru";

    for(int i=0 ; i<2 ; i++)
    {
        printf("ID : %d ,NAME : %s\n",students[i].id,students[i].name);
    }

    return 0;
    
}