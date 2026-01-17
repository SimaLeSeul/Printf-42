#include "ft_printf.h"

int ft_putptr(void *ptr)
{
    int count = 0;
    unsigned long addr = (unsigned long)ptr;
    
    if (ptr == NULL)
        return (ft_putstr("(nil)"));
    
    count += ft_putstr("0x");
    count += ft_puthex(addr);
    
    return (count);
}