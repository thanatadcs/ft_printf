/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 16:50:57 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/10 18:20:30 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(void *data)
{
	char c;

	c = (size_t) data;
	return (write(1, &c, 1));
}

// write() can return -1.
int	ft_putstr(void *data)
{
	char	*s;
	ssize_t	num_printed;

	s = (char *) data;
	num_printed = 0;
	while (*s)
		num_printed += write(1, s++, 1);
	return (num_printed);
}

int	ft_putnbr(void *data)
{
	int	n;

	return (0);
}

int	ft_puthex_lower(void *data)
{
	(void) data;
	return (0);
}

int	ft_puthex_upper(void *data)
{
	(void) data;
	return (0);
}
