#include <stdio.h>

void traverse(int arr[], int size)
{
    for(int i=0 ; i<size ; i++)
    {
        printf("%d  ",arr[i]);
    }
    printf("\n");
}

void insertatbeginning(int arr[], int *size, int value)
{
    for(int i=*size ; i>0 ; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[0] = value;
    (*size)++;
}

void inseratend(int arr[] , int*size , int value)
{
    arr[*size] = value;
    (*size)++;
}

void insertatposition(int arr[] , int *size , int pos, int value)
{
    if(pos<0  || pos>*size)
    {
        printf("Invalid position\n");
        return;
    }
    for(int i= *size; i>pos ; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[pos] = value;
    (*size)++;
}

void deletefrombeginning(int arr[] , int *size)
{
    if(*size == 0)
    {
        printf("Array is empty\n");
        return ;
    }
    for(int i=0 ; i<*size-1 ; i++)
    {
        arr[i] = arr[i+1];
    }
    (*size)--;
}

void deletefromend(int arr[] , int *size)
{
    if(*size == 0)
    {
        printf("array is empty\n");
        return;
    }
    for(int i=0 ; i<*size-1 ; i++)
    {
        arr[i] = arr[i+1];
    }
    (*size)--;
}

void deletefromposition(int arr[] , int *size , int pos)
{
    if(pos<0 || pos>*size)
    {
        printf("Invalid position\n");
        return;
    }
    for(int i=pos ; i<*size-1 ; i++)
    {
        arr[i] = arr[i+1];
    }
    (*size)--;
}

int main()
{
    int arr[10] = {10,20,30,40,50};
    int size = 5;

    printf("original array:");
    traverse(arr,size);

    insertatbeginning(arr,&size,5);
    printf("After inserting 5 at beginning:");
    traverse(arr,size);

    inseratend(arr,&size,60);
    printf("After inserting 60 at end:");
    traverse(arr,size);

    insertatposition(arr,&size,3,25);
    printf("After inserting 25 at position 3:");
    traverse(arr,size);

    deletefrombeginning(arr,&size);
    printf("After deleting from beginning:");
    traverse(arr,size);

    deletefromend(arr,&size);
    printf("After deleting from end:");
    traverse(arr,size);

    deletefromposition(arr,&size,2);
    printf("After deleting from position 2:");
    traverse(arr,size);

    return 0;
}