/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 02:20:35 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/11 08:00:20 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_flag(const char *s, va_list *args_ptr)
{
	int	to_return;
	va_list args;

	to_return = 0;
	args = *args_ptr;
	if (*s == 'c')
		to_return = ft_putchar(va_arg(args, int));
	else if (*s == 's')
		to_return = ft_putstr(va_arg(args, char *));
	else if (*s == 'p')
		 to_return =  ft_putstr("0x") + ft_puthex_lower(va_arg(args, uintptr_t));
	else if (*s == 'd' || *s == 'i')
		 to_return = ft_putnbr(va_arg(args, int));
	else if (*s == 'u')
		 to_return = ft_putnbr(va_arg(args, unsigned int));
	else if (*s == 'x')
		to_return =ft_puthex_lower(va_arg(args, unsigned int));
	else if (*s == 'X')
		to_return = ft_puthex_upper(va_arg(args, unsigned int));
	else if (*s == '%')	
		to_return = ft_putchar(*s);
	else if (*s != '\0')
		to_return = ft_putchar(*s);
	*args_ptr = args;
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

void	wrapper(va_list args)
{
	va_arg(args, char *);
}

void	test(int n, ...)
{
	va_list args;
	char *arg;
	va_start(args, n);
	printf("%c\n", (char)va_arg(args, int));
	arg = va_arg(args, char *);
	printf("%s\n", arg);
	va_end(args);
}

#include <stdio.h>
int	main(void)
{
	int	a;

	printf("%c %s %p %d %i %u %x %X %%\n", 'c', "str", &a, 42, 42, -1, 32, 32);
	ft_printf("%c %s %p %d %i %u %x %X %%\n", 'c', "str", &a, 42, 42, -1, 32, 32);
	test(2, 'c', "str");
}
