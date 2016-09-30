# Assertions in C

An assertion specifies that a program satisfies certain conditions at
particular points in its execution. There are three types of
assertion:

- Preconditions: specify conditions at the start of a function.

- Postconditions: specify conditions at the end of a function.

- Invariants: specify conditions over a defined region of a program.

An assertion violation indicates a bug in the program or in the algorithm.


The argument to assert must be true when the macro is executed,
otherwise the program aborts and prints an error message.

```
#include <assert.h>

  assert( size1 == size2 );
```

By default, ANSI C compilers generate code to check assertions at
run-time. Assertion-checking can be turned off by defining the NDEBUG
flag to your compiler

```
 gcc -DNDEBUG check.c
```