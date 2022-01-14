/* { dg-do compile } */
/* { dg-options "-march=rv64gc_zicbop -mabi=lp64" } */

int foo1(int rs1)
{
    return __builtin_riscv_prefetchi(rs1);
}

int foo2(int rs1)
{
    return __builtin_riscv_prefetchr(rs1);
}

int foo3(int rs1)
{
    return __builtin_riscv_prefetchw(rs1);
}
/* { dg-final { scan-assembler-times "prefetch.i" 1 } } */
/* { dg-final { scan-assembler-times "prefetch.r" 1 } } */
/* { dg-final { scan-assembler-times "prefetch.w" 1 } } */