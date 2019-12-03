#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    unsigned char* p_s = (unsigned char*)s + mx_strlen(s) - 1;

    while(n--) {
        if (*(p_s) == c)
            return (p_s);
        p_s--;
    }
    return NULL;
}

