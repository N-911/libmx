#include "libmx.h"

void *mx_memset(void *b, int c, size_t len) {
    unsigned char *pointer = b;

    while (len--) {
        *pointer++ = (unsigned char)c;
    }
    return b;
}

