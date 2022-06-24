#include <stdio.h>
#include <string.h>

int main()
{
    int a = 2;
    int b = 3;
    int c = 0;
    int d = 4;

    register int *ap asm ("a0") = &a;
    register int *bp asm ("a1") = &b;
    register int *cp asm ("s1") = &c;
    register int *dp asm ("s2") = &d;

    asm volatile(
        "mv %0, %1    \n\t"
        "mv %2, %3    \n\t"
        : "=r" (ap), "=r" (cp)
        : "r" (bp), "r" (dp)
    );
    printf("a = %d, b = %d, c = %d, d = %d\n", a, b, c, d);
    asm volatile(
        "mv %0, %2    \n\t"
        "mv %1, %3    \n\t"
        : "=r" (cp), "=r" (dp)
        : "r" (ap), "r" (bp)
    );
    printf("a = %d, b = %d, c = %d, d = %d\n", a, b, c, d);
    return 0;
}