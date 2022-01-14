/* { dg-do compile } */
/* { dg-options "-march=rv64gc_zicboz -mabi=lp64" } */

int foo1()
{
    return __builtin_riscv_zero();
}

/* { dg-final { scan-assembler-times "cbo.zero" 1 } } */