/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibaboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 22:37:24 by mibaboul          #+#    #+#             */
/*   Updated: 2026/10/10 23:11:24 by mibaboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count = ft_putnbr_unsigned(n / 10);
	if (count == -1 || ft_putchar((n % 10) + '0') == -1)
		return (-1);
	return (count + 1);
}
