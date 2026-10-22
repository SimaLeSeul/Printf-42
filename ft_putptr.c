/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibaboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 22:04:26 by mibaboul          #+#    #+#             */
/*   Updated: 2026/10/10 23:13:13 by mibaboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr_hex(unsigned long addr)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0123456789abcdef";
	if (addr > 15)
		count += ft_putptr_hex(addr / 16);
	count += ft_putchar(hex[addr % 16]);
	return (count);
}

int	ft_putptr(void *ptr)
{
	if (!ptr)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	return (ft_putptr_hex((unsigned long)ptr) + 2);
}
