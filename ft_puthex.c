/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibaboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 22:39:27 by mibaboul          #+#    #+#             */
/*   Updated: 2026/10/10 23:10:42 by mibaboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0123456789abcdef";
	if (n > 15)
		count = ft_puthex(n / 16);
	if (count == -1 || ft_putchar(hex[n % 16]) == -1)
		return (-1);
	return (count + 1);
}
