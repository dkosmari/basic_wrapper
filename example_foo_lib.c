#include <stdlib.h>
#include <stdio.h>

#include "example_foo_lib.h"


struct Foo {
    int value;
};


Foo*
foo_create(int arg)
{
    Foo* f = malloc(sizeof(Foo));
    if (f) {
        f->value = arg;
        printf("Created Foo{%d}\n", f->value);
    }
    return f;
}


void
foo_destroy(Foo* f)
{
    if (f) {
        printf("Destroying Foo{%d}\n", f->value);
        free(f);
    }
}


void
foo_do_something(Foo* f)
{
    printf("Doing something with Foo{%d}\n", f->value);
}
