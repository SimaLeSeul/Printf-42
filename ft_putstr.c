#include "ft_printf.h"

int ft_putstr(const char *format)
{
    int count;

    count = 0;
    if (!format)
        format = "(null)";
    while (format[count])
    {
        ft_putchar(format[count]);
        count++;
    }
    return (count);
}