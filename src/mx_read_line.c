#include "libmx.h"
static char *str_join(const char *s1, const char *s2);
 
int mx_read_line(char **lineptr, int buf_size, char delim, const int fd) {
    static char * str_a_delim = NULL;
    char buf[buf_size + 1];
    char *temp = NULL;
    char *temp_d = NULL;
    char *str_n = NULL;
    int index_c;
    int read_b;

    if (fd < 0) {
        *lineptr = NULL;
        return -1;
    }
    if (buf_size == 0)
        return mx_strlen(*lineptr);
    if (str_a_delim != NULL)
        str_n = mx_strdup(str_a_delim);
    while ((read_b = read(fd, &buf, buf_size)) >= 0) {
        buf[read_b] = '\0';
        index_c = mx_get_char_index(buf, delim);
        temp = mx_strdup(buf);
        if (index_c >= 0) {
            temp_d = mx_strnew(index_c + 1);
            temp_d = mx_strncpy(temp_d, temp ,index_c);
            str_n = str_join(str_n, temp_d);
            if (str_a_delim)
                mx_strdel(&str_a_delim);
            str_a_delim = mx_strdup(temp + index_c + 1);
            mx_strdel(&temp);
            mx_strdel(&temp_d);
            break;
        }
        str_n = str_join(str_n, temp);
        mx_strdel(&temp);
        if (read_b == 0) {
            if (str_a_delim)
                mx_strdel(&str_a_delim);
            *lineptr = NULL;
        break;
        }
    }
    *lineptr = mx_strdup(str_n);
    mx_strdel(&str_n);
    return mx_strlen(*lineptr);
}

static char *str_join(const char *s1, const char *s2) {
    if (!s1 && !s2)
        return NULL;
    else if (!s1 && s2)
        return mx_strdup(s2);
    else if (s1 && !s2)
        return mx_strdup(s1);
    else {
        char * str = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
        mx_strcpy(str, s1);
        mx_strcpy((str + mx_strlen(s1)), s2);
        return str ? str : NULL;
    }
}

