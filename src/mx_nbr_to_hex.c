#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    short len_hex = 0 ;
    char *hex;

    for (unsigned long l = nbr; l > 0; l /= 16, len_hex++);
    hex = mx_strnew(len_hex);
    if (nbr ==  0) {
        hex = mx_strnew(1);
        hex[0] = '0';
        return hex;
    }
    else {
        hex = mx_strnew(len_hex);
        for (short j = len_hex - 1; nbr > 0; j--) {
            if (nbr % 16 < 10)
                hex[j] = nbr % 16 + 48;
            else
                hex[j] = nbr % 16 + 87;
            nbr /= 16;
        }
    return hex;
    }
}

