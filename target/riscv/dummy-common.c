#include "qemu/osdep.h"
#include "qemu/host-utils.h"
#include "fpu/softfloat.h"
#include "target/riscv/cpu.h"
#include "target/riscv/internals.h"

/* Vector Floating-Point Classify Instruction */
uint16_t fclass_h(float16 frs1)
{
    bool sign = float16_is_neg(frs1);

    if (float16_is_infinity(frs1)) {
        return sign ? 1 << 0 : 1 << 7;
    } else if (float16_is_zero(frs1)) {
        return sign ? 1 << 3 : 1 << 4;
    } else if (float16_is_zero_or_denormal(frs1)) {
        return sign ? 1 << 2 : 1 << 5;
    } else if (float16_is_any_nan(frs1)) {
        float_status s = { }; /* for snan_bit_is_one */
        return float16_is_quiet_nan(frs1, &s) ? 1 << 9 : 1 << 8;
    } else {
        return sign ? 1 << 1 : 1 << 6;
    }
}

uint16_t fclass_s(float32 frs1)
{
    bool sign = float32_is_neg(frs1);

    if (float32_is_infinity(frs1)) {
        return sign ? 1 << 0 : 1 << 7;
    } else if (float32_is_zero(frs1)) {
        return sign ? 1 << 3 : 1 << 4;
    } else if (float32_is_zero_or_denormal(frs1)) {
        return sign ? 1 << 2 : 1 << 5;
    } else if (float32_is_any_nan(frs1)) {
        float_status s = { }; /* for snan_bit_is_one */
        return float32_is_quiet_nan(frs1, &s) ? 1 << 9 : 1 << 8;
    } else {
        return sign ? 1 << 1 : 1 << 6;
    }
}

uint16_t fclass_d(float64 frs1)
{
    bool sign = float64_is_neg(frs1);

    if (float64_is_infinity(frs1)) {
        return sign ? 1 << 0 : 1 << 7;
    } else if (float64_is_zero(frs1)) {
        return sign ? 1 << 3 : 1 << 4;
    } else if (float64_is_zero_or_denormal(frs1)) {
        return sign ? 1 << 2 : 1 << 5;
    } else if (float64_is_any_nan(frs1)) {
        float_status s = { }; /* for snan_bit_is_one */
        return float64_is_quiet_nan(frs1, &s) ? 1 << 9 : 1 << 8;
    } else {
        return sign ? 1 << 1 : 1 << 6;
    }
}
