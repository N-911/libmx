#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    const unsigned char *p_s1 = s1;
    const unsigned char *p_s2 = s2;

    while (n--) {
        if (*p_s1 != *p_s2)
            return p_s1 - p_s2;
        else {
            p_s1++;
            p_s2++;
        }
    }
    return 0;
}

