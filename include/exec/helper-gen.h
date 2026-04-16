/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 * Helper file for declaring TCG helper functions.
 * This one expands generation functions for tcg opcodes.
 */

#ifndef HELPER_GEN_H
#define HELPER_GEN_H

#include "exec/helper-gen-common.h"

#ifdef HELPER_INCLUDE_COMMON
# undef HELPER_TARGET_SUFFIX
# define HELPER_H "helper-common.h"
# include "exec/helper-gen.h.inc"
# undef  HELPER_H
#endif

#ifdef HELPER_INCLUDE_TARGET
# define HELPER_TARGET_SUFFIX
# define HELPER_H "helper-target.h"
# include "exec/helper-gen.h.inc"
# undef  HELPER_H
#endif

#ifndef HELPER_SPLIT_TARGET
# define HELPER_H "helper.h"
# include "exec/helper-gen.h.inc"
# undef  HELPER_H
#endif

#endif /* HELPER_GEN_H */
