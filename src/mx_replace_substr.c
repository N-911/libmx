#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if (!str || !sub || !replace)
        return NULL;

    int c_sub = mx_count_substr(str, sub);
    int len_sub = mx_strlen(sub);
    int len_str = mx_strlen(str);
    int len_rep = mx_strlen(replace);
    char *new_str = mx_strnew(len_str - c_sub * len_sub + c_sub * len_rep);

    for (int i, p = 0, p_n = 0, j = 0; j < c_sub; j++) {
        i = mx_get_substr_index((str + p), sub);
        mx_strncpy((new_str + p_n), (str + p), i);
        mx_strcat((new_str), replace);
        p_n += i + len_rep;
        p += i + len_sub;
    }
    return new_str;
}

