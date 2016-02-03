#include "test.h"

struct Foo {
    int internal_value;
    struct os_callback * callbacks;
};

Foo * new_foo()
{
    Foo * foo = (Foo *)malloc(sizeof(Foo));
    foo->internal_value = 0;
    return foo;
}

void free_foo(Foo * foo) {
    free(foo);
}

struct os_callback * foo_new_callbacks(
    int (*add_two_numbers)(int a, int b)) {
    struct os_callback * callbacks = (struct os_callback *)malloc(sizeof(struct os_callback));
    callbacks->add_two_numbers = add_two_numbers;
    return callbacks;
}

void foo_free_callbacks(struct os_callback * cb) {
    free(cb);
}

void foo_set_callbacks(Foo * foo, struct os_callback * cb) {
    foo->callbacks = cb;
}

int foo_add(Foo * foo, int a, int b) {
    if (!foo) {
        fprintf(stderr, "foo is null!\n");
        return -1;
    }
    if (!foo->callbacks) {
        fprintf(stderr, "callbacks not set!\n");
        return -1;
    }
    int result = foo->callbacks->add_two_numbers(a, b);
    fprintf(stderr, "result=%d\n", result);
    foo->internal_value = result;
    return result;
}

int foo_get_internal_value(Foo * foo) {
    if (!foo) {
        fprintf(stderr, "foo is null\n");
        return -1;
    }
    return foo->internal_value;
}
