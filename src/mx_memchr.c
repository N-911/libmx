#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    unsigned char* p_s = (unsigned char*)s;

    while (n--) {
        if (*p_s == c)
            return p_s;
        p_s++;
    }
    return NULL;
}

