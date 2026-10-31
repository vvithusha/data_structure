#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int *num , *data;
    data = malloc(sizeof(int)*10);//get the space for 10 numbers 
    num = data;  
    
    for(int i=0 ; i<5 ;i++)
    {
        num[i] = 2*i;
        printf("%d\n",num[i]);
    }   
    free(data);
    return 0;
}