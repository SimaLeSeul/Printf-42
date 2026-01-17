#include "ft_printf.h"

int ft_puthex_upper(unsigned int n)
{
    int count;
    char *hex;

    hex = "0123456789ABCDEF";
    count = 0;
    if (n >= 16)
        count += ft_puthex_upper(n / 16);
    count += ft_putchar(hex[n % 16]);
    return (count);
}