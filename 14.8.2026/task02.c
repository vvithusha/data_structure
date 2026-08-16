#include <stdio.h>
int main()
{
    int arr[5] = {2,4,6,8,10};
    int *p = arr;

    for(int i=0 ; i<5 ; i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n\n");
    for(int i=0 ; i<5 ; i++)
    {
        printf("%d\n",*(p+i));
    }
    return 0;
}