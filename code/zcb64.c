/* { dg-do run } */
/* { dg-options "-march=rv64g_zba_zbb_zca_zcb -mabi=lp64d" } */

#include <stdio.h>
#include <stdint.h>

void lbu_sb(unsigned char arr[])
{
    unsigned char a = arr[0];
    arr[0] = a + 1;
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
        printf("c.lh PASS!\n");
    }
}

void ext(void)
{
    unsigned char a = 2;
    signed char b = -2;
    unsigned short c = 3;
    signed short d = -3;
    unsigned int e = 255;

    asm volatile(
        "zext.b %0, %1"
        : "=r" (a)
        : "r" (a)
    );
    
    asm volatile(
        "sext.b %0, %1"
        : "=r" (b)
        : "r" (b)
    );

    asm volatile(
        "zext.h %0, %1"
        : "=r" (c)
        : "r" (c)
    );

    asm volatile(
        "sext.h %0, %1"
        : "=r" (d)
        : "r" (d)
    );

    asm volatile(
        "zext.w %0, %1"
        : "=r" (e)
        : "r" (e)
    );

    printf("a = %d, b = %d, c = %d, d = %d, e = %d\n", a, b, c, d, e);
}

void mul(void)
{
    int m = 1;
    int n = 2;

    asm volatile(
        "mul %0,%1,%2"
        : "=r" (m)
        : "r" (m),"r" (n)
    );
    printf("m = %d, n = %d\n", m, n);
}

void not(void)
{
    int p = 1;
    asm volatile(
        "not %0,%1"
        : "=r" (p)
        : "r" (p)
    );
    printf("p = %d\n", p);
}

int main()
{
    unsigned char arr1[] = {0,127,255};
    unsigned short arr2[] = {0,256,32213,65535};
    signed short arr3[] = {0,-127,127,32768};
    lbu_sb(arr1);
    lhu_sh(arr2);
    lh(arr3);
    ext();
    mul();
    not();
    if (arr1[0] == 1)
    {
        printf("c.lbu and c.sb PASS!\n");
    }
    if (arr2[1] == 257)
    {
        printf("c.lhu and c.sh PASS!\n");
    }
    return 0;
}