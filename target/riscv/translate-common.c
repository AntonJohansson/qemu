#include "qemu/osdep.h"

#define HELPER_SPLIT_TARGET
#define HELPER_INCLUDE_COMMON
#include "exec/helper-proto.h"

#undef HELPER_TARGET_SUFFIX
#define HELPER_H "helper-common.h"
#include "exec/helper-info.c.inc"
#undef  HELPER_H
