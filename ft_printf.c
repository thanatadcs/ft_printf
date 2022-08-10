/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 02:20:35 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/10 18:18:01 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	initialize_conv(t_conv *conv)
{
	if (conv[0].flag == 0)
	{
		conv[0].flag = 'c';
		conv[0].func = ft_putchar;
		conv[1].flag = 's';
		conv[1].func = ft_putstr;
		conv[2].flag = 'p';
		conv[2].func = ft_puthex_lower;
		conv[3].flag = 'd';
		conv[3].func = ft_putnbr;
		conv[4].flag = 'i';
		conv[4].func = ft_putnbr;
		conv[5].flag = 'u';
		conv[5].func = ft_putnbr;
		conv[6].flag = 'x';
		conv[6].func = ft_puthex_lower;
		conv[7].flag = 'X';
		conv[7].func = ft_puthex_upper;
	}
}

static void	check_flag(const char *s, va_list args, int num_printed)
{
	(void) num_printed;
	static t_conv	conv[9];
	short			i;

	initialize_conv(conv);
	i = -1;
	while (++i < 9)
	{
		if (*s == conv[i].flag || *s == '%')
		{
			if (*s == '%')
				write(1, "%", 1);
			else
				conv[i].func(va_arg(args, void *));
			return ;
		}
	}
	/*
	if (*s == 'c')
		ft_putchar(va_arg(args, void *));
	else if (*s == 's')
		ft_putstr(va_arg(args, char *));
	else if (*s == 'p')
		ft_puthex_lower(va_arg(args, size_t));
	else if (*s == 'd' || *s == 'i')
		ft_putnbr(va_arg(args, int));
	else if (*s == 'u')
		ft_putnbr(va_arg(args, unsigned int));
	else if (*s == 'x')
		ft_puthex_lower(va_arg(args, unsigned int));
	else if (*s == 'X')
		ft_puthex_upper(va_arg(args, unsigned int));
	else if (*s == '%')	
		ft_putchar(*s);
	else if (*s != '\0')
		ft_putchar(*s);
	*/
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
			check_flag(++s, args, num_printed);
		else
			write(1, s, 1);
		s += (*s != '\0');
	}
	va_end(args);	
	return (num_printed);
}

int	main(void)
{
	ft_printf("hello, world%s\n", " sai");
}
