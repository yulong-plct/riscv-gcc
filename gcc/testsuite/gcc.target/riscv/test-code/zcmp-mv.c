#include <stdio.h>
#include <string.h>

int main()
{
    asm volatile(
        "mv a0, s1    \n\t"
        "mv a0, s1    \n\t"
        "mv a1, s2    \n\t"
        "mv a0, s1    \n\t"
        "mv a0, s8    \n\t"
    );
    asm volatile(
        "mv s1, a0    \n\t"
        "mv s2, a0    \n\t"
        "mv s1, a0    \n\t"
        "mv s2, a1    \n\t"
        "mv s1, a0    \n\t"
        "mv s8, a0    \n\t"
    );
    printf("zcmp-mv PASS!\n");
    return 0;
}