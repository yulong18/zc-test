/* { dg-do run } */
/* { dg-options "-march=rv32g_zca_zcb_zcmb -mabi=ilp32" } */

#include <stdio.h>

void lbu_sb(unsigned char arr[])
{
    unsigned char a = arr[0];
    arr[0] = a + 1;
}

void lb(signed char arr[])
{
    signed char a[1] = {0};
    a[0] = arr[4];
    if (a[0] == 3)
    {
        printf("cm.lb PASS!\n");
    }
    else
    {
        printf("cm.lb FAIL!\n");
    }
}

void lhu_sh(unsigned short arr[])
{
    unsigned short a = arr[1];
    arr[1] = a + 1;
}

void lh(signed short arr[])
{
    signed short a[1] = {0};
    a[0] = arr[1];
    if (a[0] == -127)
    {
        printf("cm.lh PASS!\n");
    }
    else
    {
        printf("cm.lh FAIL!\n");
    }
}

int main()
{
    unsigned char arr1[] = {0,127,255};
    signed char arr2[] = {-127, 0, 128, 0, 3};
    unsigned short arr3[] = {0,256,32213,65535};
    signed short arr4[] = {0,-127,127,32768};
    lbu_sb(arr1);
    lb(arr2);
    lhu_sh(arr3);
    lh(arr4);
    if (arr1[0] == 1)
    {
        printf("cm.lbu and cm.sb PASS!\n");
    }
    else
    {
        printf("cm.lbu and cm.sb FAIL!\n");
    }

    if (arr3[1] == 257)
    {
        printf("cm.lhu and cm.sh PASS!\n");
    }
    else
    {
        printf("cm.lhu and cm.sh FAIL!\n");
    }
    return 0;
}