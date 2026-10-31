#include <stdio.h>
#include <string.h>
struct book
{
    int id;
    char name[50];
    float price;
};
int main()
{
    int x=10;
    int *p = &x;
    printf("%d\n",*p);
    struct book book1,book2;

    book1.id=101;
    strcpy(book1.name,"vithu");
    book1.price = 950.50;

    printf("ID : %d\n",book1.id);
    printf("NAME : %s\n",book1.name);
    printf("PRICE : %.2f\n",book1.price);
    
    return 0;
}