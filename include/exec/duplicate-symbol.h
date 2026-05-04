/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 * Helper file for naming TCG helper functions with
 * optional target specific size suffixes.
 */

#ifndef DUPLICATE_SYMBOL_H
#define DUPLICATE_SYMBOL_H

/*
 * Suffix per-target helpers with target size to allow for duplication
 * of helpers in a single-binary target.
 */
#define DUPSYM(name) glue(name, glue(_tl, TARGET_LONG_BITS))

#endif /* DUPLICATE_SYMBOL_H */
