#if !defined(TEST_INCLUDED_)
#define TEST_INCLUDED_

#include <stdlib.h>
#include <stdio.h>

// We dont know what is it... yet!
typedef struct Foo Foo;

struct os_callback {
    /**
     * OS implementation of "+" mathematical operation
     */
    int (*add_two_numbers)(int a, int b);
};

/**
 * Create new instance of Foo
 */
Foo * new_foo();

/**
 * Free instance of foo
 */
void free_foo(Foo * foo);

/**
 * OS callbacks structure which you should implement.
 */
struct os_callback * foo_new_callbacks(
  int (*add_two_numbers)(int a, int b)
);

/**
 * Free callbacks memory 
 */
void foo_free_callbacks(struct os_callback * cb);

/**
 * Set OS callback for instance of foo
 */
void foo_set_callbacks(Foo * foo, struct os_callback * cb);

/**
 * Do some crazy computation using OS callbacks
 */
int foo_add(Foo * foo, int a, int b);

/**
 * Get some hidden treasure from our mysterious structure
 */
int foo_get_internal_value(Foo * foo);

#endif
