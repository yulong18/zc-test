/* { dg-do run } */
/* { dg-options "-march=rv32g_zca_zcmp -mabi=ilp32d -O1" } */

#include <stdio.h>

int main()
{
    printf("cm.push and cm.popretz PASS!\n");
    return 0;
}
