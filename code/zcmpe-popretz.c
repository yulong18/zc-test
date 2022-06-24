/* { dg-do run } */
/* { dg-options "-march=rv32e_zca_zcmpe -mabi=ilp32e" } */

#include <stdio.h>

short fun(short x)
{
    x = 2;
    return 0;
}

int main()
{
    short a =1;
    printf("aaaa is %d", a);
    return 0;
}
