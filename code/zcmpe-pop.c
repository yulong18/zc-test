/* { dg-do run } */
/* { dg-options "-march=rv32e_zca_zcmpe -mabi=ilp32e" } */

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