#include "ft_printf.h"

int ft_putnbr(int n)
{
    int count;
    long long nb;

    nb = n;
    count = 0;
    if (n < 0)
    {
        count += ft_putchar('-');
        nb = -nb;
    }
    if (nb >= 10)
        count += ft_putnbr((nb / 10));
    count += ft_putchar('0' + (nb % 10));
    return (count);
}