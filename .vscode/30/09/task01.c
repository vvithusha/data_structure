#include <stdio.h>
#define SIZE 15
void traverse(int arr[] , int n)
{
    for(int i=0 ; i<n ; i++)
    {
        printf(" %d" , arr[i]);        
    }
    printf("\n");
}

void insertatbeginning(int value , int arr[] , int *n)
{
    if(*n >= SIZE)
    {
        printf("array is full\n");
    }
    for(int i = *n ; i>0 ; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[0] = value;
    (*n)++;
}

void insertatend(int array[] , int value , int *n)
{
    array[*n] = value;
    (*n)++;
}

void insertAtPosition(int array[] , int value , int position , int *n)
{
    if(*n >= SIZE)
    {
        printf("Array Size is full!");
    }
    else
    {
        if(position<0 || position>*n)
        {
            printf("Invalid input");
        }
        
        for(int i= *n ; i>position ; i--)
        {
            array[i] = array[i-1];
        }
        array[position] = value;
        (*n)++;
    }
}

void delete(int array[] ,int *n)
{
    if(*n == 0)
    {
        printf("Empty array!");
        return;
    } 
    for(int i = 0 ; i<(*n - 1) ; i++)
    {
        array[i] = array[i+1];
    }
    (*n)--;
}

void deleteposition(int arr[] , int *n , int pos)
{
    if(pos>*n || pos<0)
    {
        printf("Invalid Position \n");
        return;
    }

    for(int i=pos ; i < *n-1 ; i++)
    {
        arr[i] = arr[i+1];
    }
    (*n)--;
}
int main()
{
    int array[SIZE] = {10,20,30,40,50};
    traverse(array , 5);

    int n=5 ;
    insertatbeginning(90 , array ,&n);

    for(int i=0 ; i<n  ; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    insertatend(array , 150 , &n);
    for(int i=0 ; i<n  ; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");   


    insertAtPosition(array, 250 , 5 , &n);
    for(int i=0 ; i<n  ; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");  

    delete(array ,&n);

    for(int i=0 ; i<n  ; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");  
    deleteposition(array, &n ,5);
    for(int i=0 ; i<n  ; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");  
    return 0;
}