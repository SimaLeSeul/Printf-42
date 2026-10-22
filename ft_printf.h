/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibaboul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 20:26:51 by mibaboul          #+#    #+#             */
/*   Updated: 2026/10/10 23:14:17 by mibaboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_printf(const char *s, ...);
int		ft_putstr(char *str);
int		ft_putptr(void *ptr);
int		ft_putnbr_unsigned(unsigned int n);
int		ft_puthex(unsigned int n);
int		ft_puthexu(unsigned int n);

#endif