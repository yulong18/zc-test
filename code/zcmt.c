#include <stdio.h>
#include <string.h>

int main ()
{
    int a[10] = {1,2,3,4,5,6};
    int b[10] = {0};
    memcpy(b,a,10);
    printf("%d\n",b[1]);
    return 0;
    
}
