#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int num[4]={2,4,6,8};
    //num=malloc(sizeof(int)*5);  // garbage value
    printf("%d\n",&num[2]);

    return 0;
}