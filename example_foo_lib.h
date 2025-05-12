/*
 * basic_wrapper - base class for C++ wrappers
 * Copyright 2025  Daniel K. O. (dkosmari)
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
*/

#ifndef EXAMPLE_FOO_LIB_H
#define EXAMPLE_FOO_LIB_H

#ifdef __cplusplus
extern "C" {
#endif


typedef struct Foo Foo;

Foo* foo_create(int arg);

void foo_destroy(Foo* f);

void foo_do_something(Foo* f);


#ifdef __cplusplus
}
#endif

#endif
