/* { dg-do run } */
/* { dg-options "-march=rv32g_zca_zcmp -mabi=ilp32d" } */

#include <stdio.h>

int main()
{
    printf("cm.push and cm.popret PASS!\n");
    return 0;
}
