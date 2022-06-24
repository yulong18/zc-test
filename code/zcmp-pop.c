/* { dg-do run } */
/* { dg-options "-march=rv32g_zca_zcmp -mabi=ilp32d" } */

#include <stdio.h>

void __attribute__ ((interrupt ("machine"))) 
foo (void)
{
  char buf[560] = {0};
  printf("cm.pop PASS!%d\n", buf[1]);
}

int main()
{
    foo();
    return 0;
}
