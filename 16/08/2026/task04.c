#include <stdio.h>
#include <string.h>

int main()
{
    int i;
    struct student
    {
        /* data */
        int id;
        char *name;

    };
    struct student s1[2] = {{101,"vithu"},{102,"saraa"}};
    
    for(i=0 ; i<2 ; i++)
    {
        printf("ID : %d, NAME : %s\n",s1[i].id,s1[i].name);
    }
    
    
    return 0;
}