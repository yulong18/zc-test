/* { dg-do run } */
/* { dg-options "-march=rv32e_zca_zcmpe -mabi=ilp32e" } */

#include <stdio.h>

int fun(int *x, int *y)
{
    *(x) = *(y);
    return 0;
}

int main()
{
    int a =1;
    int b =2;
    fun(&a, &b);
    return 0;
}