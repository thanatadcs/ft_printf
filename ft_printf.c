/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 02:20:35 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/11 19:04:06 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_flag(const char *s, va_list *args_ptr)
{
	int		to_return;

	to_return = 0;
	if (*s == 'c')
		to_return = ft_putchar(va_arg(*args_ptr, int));
	else if (*s == 's')
		to_return = ft_putstr(va_arg(*args_ptr, char *));
	else if (*s == 'p')
		to_return = ft_putstr("0x") + \
		ft_puthex(va_arg(*args_ptr, uintptr_t), 0);
	else if (*s == 'd' || *s == 'i')
		to_return = ft_putnbr(va_arg(*args_ptr, int));
	else if (*s == 'u')
		to_return = ft_putnbr(va_arg(*args_ptr, unsigned int));
	else if (*s == 'x')
		to_return = ft_puthex(va_arg(*args_ptr, unsigned int), 0);
	else if (*s == 'X')
		to_return = ft_puthex(va_arg(*args_ptr, unsigned int), 1);
	else if (*s == '%')
		to_return = ft_putchar(*s);
	else if (*s != '\0')
		to_return = ft_putchar(*s);
	return (to_return);
}

int	ft_printf(const char *s, ...)
{
	va_list			args;
	int				num_printed;

	va_start(args, s);
	num_printed = 0;
	while (*s)
	{
		if (*s == '%')
			num_printed += check_flag(++s, &args);
		else
			num_printed += write(1, s, 1);
		s += (*s != '\0');
	}
	va_end(args);
	return (num_printed);
}
