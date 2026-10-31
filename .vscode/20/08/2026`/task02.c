#include <stdio.h>

int main()
{
    int a = 10;
    int *p = &a;

    printf("Address of a : %p\n", &a);   // address of a
    printf("Value of p   : %p\n", p);    // same address, stored in p
    printf("Value of a   : %d\n", a);    // actual value
    printf("Value at *p  : %d\n", *p);   // value pointed to by p

    return 0;
}