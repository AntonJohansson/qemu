/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 * Helper file for declaring TCG helper functions.
 * This one expands prototypes for the helper functions.
 */

#ifndef HELPER_PROTO_H
#define HELPER_PROTO_H

#include "exec/helper-proto-common.h"

#ifdef HELPER_INCLUDE_COMMON
# undef HELPER_TARGET_SUFFIX
# define HELPER_H "helper-common.h"
# include "exec/helper-proto.h.inc"
# undef  HELPER_H
#endif

#ifdef HELPER_INCLUDE_TARGET
# define HELPER_TARGET_SUFFIX
# define HELPER_H "helper-target.h"
# include "exec/helper-proto.h.inc"
# undef  HELPER_H
#endif

#ifndef HELPER_SPLIT_TARGET
# define HELPER_H "helper.h"
# include "exec/helper-proto.h.inc"
# undef  HELPER_H
#endif

#endif /* HELPER_PROTO_H */
