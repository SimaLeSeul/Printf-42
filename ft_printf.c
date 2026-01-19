#include "ft_printf.h"

int handle_conversion(char type, va_list *args)
{
    if (type == 'c')
        return (ft_putchar(va_arg(*args, int)));
    else if (type == 's')
        return (ft_putstr(va_arg(*args, char *)));
    else if (type == 'd' || type == 'i')
        return (ft_putnbr(va_arg(*args, int)));
    else if (type == 'u')
        return (ft_putnbr_unsigned(va_arg(*args, unsigned int)));
    else if (type == 'x')
        return (ft_puthex(va_arg(*args, unsigned int)));
    else if (type == 'X')
        return (ft_puthex_upper(va_arg(*args, unsigned int)));
    else if (type == 'p')
        return (ft_putptr(va_arg(*args, void *)));
    else if (type == '%')
        return (ft_putchar('%'));
    return (0);
}
#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
    if (!format)
        return (0);
    va_list args;
    int count;
    int i;
    
    i = 0;
    count = 0;
    va_start(args, format);
    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            count += handle_conversion(format[i], &args);
        }
        else
            count += ft_putchar(format[i]);
        i++;
    }
    va_end(args);
    return (count);
}
/*int main()
{
    ft_printf("Hello\n");
    ft_printf("%s\n", "world");
    ft_printf("%c\n", 'A');

    // Nombres
    ft_printf("%d\n", 42);
    ft_printf("%d\n", -42);
    ft_printf("%d\n", 0);
    ft_printf("%d\n", -2147483648);
    ft_printf("%u\n", 4294967295);

    // Hexa
    ft_printf("%x\n", 255);
    ft_printf("%X\n", 255);
    ft_printf("%x\n", 0);

    // Pointeurs
    int x = 42;
    ft_printf("%p\n", &x);
    ft_printf("%p\n", NULL);

    // Cas spéciaux
    ft_printf("%s\n", NULL);
    ft_printf("%%\n");
    ft_printf("%s %d %x\n", "test", 42, 255);

    // NULL
    printf(NULL);
    ft_printf(NULL);
    
}*/