#include "libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
    if (*arr && delim) {
        for ( ; *arr != NULL; arr++) {
            mx_printstr(*arr);
            if (*(arr + 1) != NULL)
                mx_printstr(delim);
        }
        mx_printstr("\n");
    }
}
