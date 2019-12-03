#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little,
                size_t little_len) {
    const char *begin;
    const char *const max_index = (const char *)big + big_len - little_len;

    if (little_len == 0 || big_len == 0 || (big_len < little_len))
        return NULL;
    for (begin = (const char *)big; begin <= max_index; begin++) {
        if ((mx_memcmp(begin, (const char *)little, little_len)) == 0)
             return (void *)begin;
    }
    return NULL;
}

