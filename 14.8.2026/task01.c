#include <stdio.h>
int trydouble (int y)
{
    return y*2;
}
int doubleit(int *y)
{
    return *y * 2;
}
int main()
{
    int x=10;
    printf("before : %d\n",x);
    printf("after : %d\n",trydouble(x));

    printf("before : %d\n",x);
    printf("after : %d\n",doubleit(&x));
    return 0;
}