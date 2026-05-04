/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 * Helper file for naming TCG helper functions with
 * optional target specific size suffixes.
 */

#ifdef HELPER_NAME
# undef HELPER_NAME
#endif

#ifdef HELPER_INFO
# undef HELPER_INFO
#endif

/*
 * Suffix per-target helpers with target size to allow for duplication
 * of helpers in a single-binary target.
 */
#ifdef HELPER_TARGET_SUFFIX
# define HELPER_NAME(name) glue(name, glue(_tl, TARGET_LONG_BITS))
#else
# define HELPER_NAME(name) name
#endif /* HELPER_PER_TARGET */

#define HELPER(name) glue(helper_, HELPER_NAME(name))

#define HELPER_INFO(name) \
    glue(helper_info_, HELPER_NAME(name))
