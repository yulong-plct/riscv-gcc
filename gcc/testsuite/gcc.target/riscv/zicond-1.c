/* { dg-do compile } */
/* { dg-options "-march=rv32gc_zicond -mabi=ilp32" } */

void foo1()
{
    __builtin_riscv_zicond_nez(1,1);
}

void foo2()
{
    __builtin_riscv_zicond_eqz(1,1);
}

/* { dg-final { scan-assembler-times "czero.nez" 1 } } */ 
/* { dg-final { scan-assembler-times "czero.eqz" 1 } } */ 
