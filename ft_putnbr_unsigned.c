#include "ft_printf.h"

int ft_putnbr_unsigned(unsigned int n)
{
    int count;

    count = 0;
    if (n >= 10)
        count += ft_putnbr((n / 10));
    count += ft_putchar('0' + (n % 10));
    return (count);
}