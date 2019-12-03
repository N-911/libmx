#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    char *temp = (char *)malloc(len);

    mx_memcpy(temp, (const char *)src, len);
    mx_memcpy((char *)dst, temp, len);
    free(temp);
    return (void *) dst;
}

