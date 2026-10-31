#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
//traversal
void traversal(int arra[] , int size)
{
    for(int i=0 ; i<size ; i++)
    {
        printf("%d ",arra[i]);
    }
    printf("\n");
}

//insert at the begining 
void insertbegin(int arr[] , int *size , int value)
{
    for(int i=*size ; i>0 ; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[0] = value;
    (*size)++;
}
void insertend(int arr[] , int *size , int value)
{
    arr[*size] = value;
    (*size)++;
}

void insertatposition(int arr[] , int *size , int value, int pos)
{
    if(pos<0 || pos >*size)
    {
        printf("Invalid position\n");
        return;
    }
    for(int i = *size ; i>pos ; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[pos] = value;
    (*size)++;
}
void deletefrombegining(int arr[] ,int *size)
{
    if(*size == 0)
    {
        printf("Array is empty\n");
        return;
    }
    for(int i=0 ; i<*size-1 ; i++)
    {
        arr[i] = arr[i+1];
    }
    (*size)--;
}

void deleterfromend(int arr[] , int *size)
{
    if(*size ==0)
    {
        printf("Empty array\n");
        return;
    }
    (*size)--;
}

void deleteposition (int arr[] , int *size , int pos)
{
   if(pos<0 || pos>*size)
   {
    printf("invalid position\n");
    return ;
   }
   for(int i=pos ; i<*size-1 ; i++)
   {
      arr[i] = arr[i+1];
   }
   (*size)--;
}
int main()
{
    int arr[SIZE] = {10,20,30,40};
    int n = 4;
    traversal(arr , n);

    insertbegin(arr , &n , 5);
    traversal(arr , n);

    insertend(arr , &n , 50);
    traversal(arr , n);

    insertatposition(arr , &n , 600 , 4);
    traversal(arr , n);

    deletefrombegining(arr , &n);
    traversal(arr , n);

    deleterfromend(arr , &n);
    traversal(arr , n);
    return 0;

}