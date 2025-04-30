/*
 * QEMU binary/target API (qemu-system-aarch64)
 *
 *  Copyright (c) Linaro
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "qemu/osdep.h"
#include "qemu/target-info-impl.h"
#include "hw/riscv/machines-qom.h"
#include "target/riscv/cpu-qom.h"
#include "qapi/qapi-types-machine.h"

static const TargetInfo target_info_riscv32_system = {
    .target_name = "riscv32",
    .target_arch = SYS_EMU_TARGET_RISCV32,
    .machine_typename = TYPE_TARGET_RISCV32_MACHINE,
};

const TargetInfo *target_info(void)
{
    return &target_info_riscv32_system;
}
