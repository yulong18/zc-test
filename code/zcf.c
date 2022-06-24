/* { dg-do run } */
/* { dg-options "-march=rv32g_zca_zcf -mabi=ilp32d" } */

#include <stdio.h>

void zcf(float arr[])
{
    float a = arr[0];
    arr[3] = a + 1;
    arr[4] = 3.14;
}

int main()
{
    float arr[] = {1.1, 0, -1.2, 0, 0};
    zcf(arr);
    if ((arr[3] != 0) && (arr[4] != 0))
    {
        printf("zcf PASS!\n");
    }
    else
    {
        printf("zcf FAIL!\n");
    }
    return 0;
}