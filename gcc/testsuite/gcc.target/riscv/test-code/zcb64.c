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
    asm volatile(
        "zext.b a1, a1"
    );
    asm volatile(
        "sext.b a1, a1"
    );
    asm volatile(
        "zext.h a1, a1"
    );
    asm volatile(
        "sext.h a1, a1"
    );
    asm volatile(
        "zext.w a1, a1"
    );
    asm volatile(
        "add.uw a1, a1, zero"
    );
    printf("ext PASS!\n");
}

void mul(void)
{
    asm volatile(
        "mul x15,x15,x8"
    );
    printf("c.mul PASS!\n");
}

void not(void)
{
    asm volatile(
        "not x15,x15"
    );
    printf("c.not PASS!\n");
}

int main()
{
    unsigned char arr1[] = {0,127,255};
    unsigned short arr2[] = {0,256,32213,65535};
    signed short arr3[] = {0,-127,127,32768};
    lbu_sb(arr1);
    lhu_sh(arr2);
    lh(arr3);
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