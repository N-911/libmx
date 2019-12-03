#include "libmx.h"

char *mx_strtrim(const char *str) {
    int size_full = mx_strlen(str);
    int count_s = 0;
    int count_e = 0;
    char * trim_str;
    int size_new;

    if (!str)
        return NULL;

    for (int i = 0; mx_isspace(str[i]); i++)
        count_s++;
    if (size_full > count_s) {
        for (int j = size_full - 1 ; mx_isspace(str[j]); j--)
            count_e++;
    }
    size_new = size_full - count_s - count_e;
    if (size_new == 0) {
        return mx_strnew(0);
    }
    else {
        trim_str = mx_strncpy(mx_strnew(size_new), (str + count_s), size_new);
        return trim_str ? trim_str : NULL;
    }
}

