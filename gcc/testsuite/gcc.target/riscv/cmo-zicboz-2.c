/* { dg-do compile } */
/* { dg-options "-march=rv32gc_zicboz -mabi=ilp32" } */

int foo1()
{
    return __builtin_riscv_zero();
}

/* { dg-final { scan-assembler-times "cbo.zero" 1 } } */