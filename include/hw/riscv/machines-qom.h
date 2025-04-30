/*
 * QOM type definitions for riscv32 / riscv64 machines
 *
 *  Copyright (c) Linaro
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef HW_RISCV_MACHINES_QOM_H
#define HW_RISCV_MACHINES_QOM_H

#include "hw/boards.h"

#define TYPE_TARGET_RISCV32_MACHINE \
        "target-info-riscv32-machine"

#define TYPE_TARGET_RISCV64_MACHINE \
        "target-info-riscv64-machine"

extern InterfaceInfo riscv32_machine_interfaces[];
extern InterfaceInfo riscv64_machine_interfaces[];
extern InterfaceInfo riscv32_64_machine_interfaces[];

#define DEFINE_MACHINE_RISCV32(namestr, machine_initfn) \
        DEFINE_MACHINE_WITH_INTERFACES(namestr, machine_initfn, \
                                       riscv32_machine_interfaces)

#define DEFINE_MACHINE_RISCV64(namestr, machine_initfn) \
        DEFINE_MACHINE_WITH_INTERFACES(namestr, machine_initfn, \
                                       riscv64_machine_interfaces)

#define DEFINE_MACHINE_RISCV32_64(namestr, machine_initfn) \
        DEFINE_MACHINE_WITH_INTERFACES(namestr, machine_initfn, \
                                       riscv32_64_machine_interfaces)

#endif
