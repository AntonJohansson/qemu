// riscv_raise_exception
#include "qemu/osdep.h"
#include "cpu.h"
#include "target/riscv/csr.h"
#include "internals.h"
#include "exec/cputlb.h"
#include "accel/tcg/cpu-ldst.h"
#include "accel/tcg/probe.h"
#define HELPER_SPLIT_TARGET
#define HELPER_INCLUDE_TARGET
#include "exec/helper-proto.h"
#include "exec/tlb-flags.h"
#include "trace.h"

// get_fflags/set_fflags
#include "qemu/osdep.h"
#include "cpu.h"
#include "qemu/host-utils.h"
#include "fpu/softfloat.h"
#include "internals.h"

/* Exceptions processing helpers */
G_NORETURN void riscv_raise_exception(CPURISCVState *env,
                                      RISCVException exception,
                                      uintptr_t pc)
{
    CPUState *cs = env_cpu(env);

    trace_riscv_exception(exception,
                          riscv_cpu_get_trap_name(exception, false),
                          env->pc);

    cs->exception_index = exception;
    cpu_loop_exit_restore(cs, pc);
}

uint8_t riscv_cpu_get_fflags(CPURISCVState *env)
{
    int soft = get_float_exception_flags(&env->fp_status);
    uint8_t hard = 0;

    hard |= (soft & float_flag_inexact) ? FPEXC_NX : 0;
    hard |= (soft & float_flag_underflow) ? FPEXC_UF : 0;
    hard |= (soft & float_flag_overflow) ? FPEXC_OF : 0;
    hard |= (soft & float_flag_divbyzero) ? FPEXC_DZ : 0;
    hard |= (soft & float_flag_invalid) ? FPEXC_NV : 0;

    return hard;
}

void riscv_cpu_set_fflags(CPURISCVState *env, uint8_t hard)
{
    int soft = 0;

    soft |= (hard & FPEXC_NX) ? float_flag_inexact : 0;
    soft |= (hard & FPEXC_UF) ? float_flag_underflow : 0;
    soft |= (hard & FPEXC_OF) ? float_flag_overflow : 0;
    soft |= (hard & FPEXC_DZ) ? float_flag_divbyzero : 0;
    soft |= (hard & FPEXC_NV) ? float_flag_invalid : 0;

    set_float_exception_flags(soft, &env->fp_status);
}
