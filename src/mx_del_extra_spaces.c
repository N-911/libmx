#include "libmx.h"

char *mx_del_extra_spaces(const char *str) {
    int word = 0;
    int j = 0;
    char *temp = mx_strnew(mx_strlen(str));

    if (!str)
        return NULL;

    for (int i = 0; i < mx_strlen(str); i++) {
      if (!(mx_isspace(str[i]))) {
         temp[j]= str[i];
         j++;
         word = 0;
      }
      else if (!word) {
         word = 1;
        temp[j] = ' ';
        j++;
      }
      else
          word = 1;
    }
    return mx_strtrim(temp);
}

