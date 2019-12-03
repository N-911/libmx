#include "libmx.h"

static int valid_hex(const char *hex, int len);
static int m_strlen(const char *s);
static unsigned int hex_number(char c);
static double m_pow(double n, unsigned int pow);

unsigned long mx_hex_to_nbr(const char *hex) {
    unsigned long result = 0;
    int len = m_strlen(hex);

    if (valid_hex(hex, len) == -1)
        return 0;
    for (int j = 0, i = len - 1; j < len; j++, i--) {
            result += hex_number(hex[j]) * m_pow(16, i);
    }
    return result;
}

static unsigned int hex_number(char c) {
    if (c >= '0' && c <= '9')
        return c - 48;
    else if (c >= 'A' && c <= 'F')
        return c - 55;
    else if (c >= 'a' && c <= 'f')
        return c -87;
    return -1;
}

static double m_pow(double n, unsigned int pow) {
    if (pow == 0)
        return 1;
    else if (pow > 0) {
        n = n * m_pow(n, pow - 1);
        return n;
    }
    else
        return n;
}

static int m_strlen(const char *s) {
    int len = 0;

    while(*s++)
        len++;
    return len;
}

static int valid_hex(const char *hex, int len) {
    for (int i = 0; i < len; i++) {
        if (!((hex[i] >= '0' && hex[i] <= '9') || (hex[i] >= 'A' && hex[i] <= 'F')
             || (hex[i] >='a' && hex[i] <= 'f')))
            return -1;
    }
    return 1;
}

