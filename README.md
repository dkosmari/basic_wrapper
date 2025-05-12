# basic_wrapper - base class for C++ wrappers

This is a simple templated class for creating wrappers to C APIs.


The [`basic_wrapper`](basic_wrapper.hpp) template class:

  - Default constructor in invalid state.

  - Check for validity: `operator bool` and `is_valid()`.

  - Explicit destruction with `.destroy() method.

  - Move constructor and move assignment, leaving the source in invalid state.

  - `.acquire()` and `.release()` idiom for transferring ownership.

  - `.data()` to access the underlying raw object.

  - Second template parameter can be used to indicate an "invalid" value. The default is
    `{}`, which will be the integer zero, or the null pointer.


Additionally, an [`owner_wrapper`](owner_wrapper.hpp) template provides an `owner` flag on
top of `basic_wrapper`:
 
 - When `owner` is `false`, the instance does not destroy the raw object.

This is a simple solution for C APIs that provide "non-ownable" pointers, that user code
is not allowed to destroy.


For more complex wrappers, you are expected to extend the `state_type` to a `std::tuple`
containing all the transferable state, so the expression `acquire(other.release())` always
works to move from one object to another.


## Licensing

This code is available under multiple licenses:

 - Apache 2.0
 - GPL 3.0 or later
 - LGPL 3.0 or later
 - MIT
 - Zlib

When distributing it with your software, you can choose which one applies for you.


## Example

See the [example.cpp](example.cpp) file for a simple way to use it.
