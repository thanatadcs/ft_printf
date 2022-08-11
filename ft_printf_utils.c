/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 16:50:57 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/10 20:42:24 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_puthex_lower(uintptr_t n)
{
	char	*hex;
	int		num_printed;
	
	hex = "0123456789abcdef";
	num_printed = 0;
	if (n >= 16)
		num_printed += ft_puthex_lower(n / 16);
	num_printed += ft_putchar(hex[n % 16]);
	return (num_printed);
}

int	ft_puthex_upper(unsigned int n)
{
	char	*hex;
	int		num_printed;

	hex = "0123456789ABCDEF";
	num_printed = 0;
	if (n >= 16)
		num_printed += ft_puthex_lower(n / 16);
	num_printed += ft_putchar(hex[n % 16]);
	return (num_printed);
}
