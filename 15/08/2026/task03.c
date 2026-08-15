#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int *num;
    num=malloc(sizeof(int)*5);  // garbage value
    printf("%d\n",num);
    return 0;
}