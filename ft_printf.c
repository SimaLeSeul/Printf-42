/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibaboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 20:26:48 by mibaboul          #+#    #+#             */
/*   Updated: 2026/10/10 23:14:02 by mibaboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_conversion(char type, va_list *ap)
{
	if (type == 'c')
		return (ft_putchar(va_arg(*ap, int)));
	else if (type == 's')
		return (ft_putstr(va_arg(*ap, char *)));
	else if (type == 'p')
		return (ft_putptr(va_arg(*ap, void *)));
	else if (type == 'd')
		return (ft_putnbr(va_arg(*ap, int)));
	else if (type == 'i')
		return (ft_putnbr(va_arg(*ap, int)));
	else if (type == 'u')
		return (ft_putnbr_unsigned(va_arg(*ap, unsigned int)));
	else if (type == 'x')
		return (ft_puthex(va_arg(*ap, unsigned int)));
	else if (type == 'X')
		return (ft_puthexu(va_arg(*ap, unsigned int)));
	else if (type == '%')
		return (write(1, "%", 1));
	return (1);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	ap;

	i = 0;
	count = 0;
	if (!format)
		return (-1);
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += handle_conversion(format[i], &ap);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
