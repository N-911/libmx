#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
    char *p_dst = dst;
    const char *p_src = src;

    while(n--) {
        *p_dst++ = *p_src++;
        if (*p_src == (unsigned char)c)
            return p_dst + 1;
    }
    return NULL;
}

