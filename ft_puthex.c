#include "ft_printf.h"

int ft_puthex(unsigned int n)
{
    int count;
    char *hex;

    hex = "0123456789abcdef";
    count = 0;
    if (n >= 16)
        count += ft_puthex(n / 16);
    count += ft_putchar(hex[n % 16]);
    return (count);
}