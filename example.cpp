/*
 * basic_wrapper - base class for C++ wrappers
 * Copyright 2025  Daniel K. O. (dkosmari)
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
*/

#include <cassert>
#include <stdexcept>
#include <utility>

#include "basic_wrapper.hpp"

#include "example_foo_lib.h"


struct foo : detail::basic_wrapper<Foo*> {

    using parent_type = detail::basic_wrapper<Foo*>;


    // Inherit constructors.
    using parent_type::parent_type;


    foo(int arg)
    {
        create(arg);
    }


    ~foo()
        noexcept
    {
        destroy();
    }


    /// Move constructor.
    foo(foo&& other)
        noexcept = default;

    /// Move assignment.
    foo&
    operator =(foo&& other)
        noexcept = default;


    void
    create(int arg)
    {
        auto new_raw = foo_create(arg);
        if (!new_raw)
            std::runtime_error{"foo_create() failed"};
        destroy();
        acquire(new_raw);
    }


    void
    destroy()
        noexcept override
    {
        if (is_valid())
            foo_destroy(release());
    }


    void
    do_something()
    {
        foo_do_something(raw);
    }

};


int main()
{
    foo a;
    assert(!a);

    a.create(17);
    assert(a);

    foo b = std::move(a);
    assert(b);
    assert(!a);

    b.do_something();

    a = foo{23};
    assert(a);
    a.do_something();

    a = std::move(b);
    a.do_something();
}
