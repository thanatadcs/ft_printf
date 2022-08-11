/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 16:50:57 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/11 17:20:15 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define LOWER 0
#define UPPER 1

int	ft_putchar(char c)
{
	int	num_printed;

	num_printed = write(1, &c, 1);
	if (num_printed < 0)
		return (0);
	return (num_printed);
}

int	ft_putstr(char *s)
{
	int	num_printed;
	int	buf;

	num_printed = 0;
	if (s == 0)
	{
		buf = write(1, "(null)", 6);
		if (buf >= 0)
			return (buf);
	}
	while (*s)
	{
		buf = write(1, s++, 1);
		if (buf >= 0)
			num_printed += buf;
	}
	return (num_printed);
}

int	ft_putnbr(long n)
{
	int	num_printed;

	num_printed = 0;
	if (n < 0)
	{
		num_printed += ft_putchar('-');
		num_printed += ft_putnbr(-1 * n);
	}
	else if (n > 9)
	{
		if (n / 10 > 0)
			num_printed += ft_putnbr(n / 10);
		num_printed += ft_putchar(n % 10 + '0');
	}
	else
		num_printed += ft_putchar(n + '0');
	return (num_printed);
}

int	ft_puthex(uintptr_t n, int mode)
{
	char	*hex;
	char	*hex_lower;
	char	*hex_upper;
	int		num_printed;

	hex_lower = "0123456789abcdef";
	hex_upper = "0123456789ABCDEF";
	hex = hex_lower;
	if (mode == UPPER)
		hex = hex_upper;
	num_printed = 0;
	if (n >= 16)
		num_printed += ft_puthex(n / 16, mode);
	num_printed += ft_putchar(hex[n % 16]);
	return (num_printed);
}
