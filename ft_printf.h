/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 02:23:46 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/10 20:42:50 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_conv
{
	char	flag;
	int		(*func)(void *);
}	t_conv;

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(long n);
int	ft_puthex_lower(uintptr_t n);
int	ft_puthex_upper(unsigned int n);
int	ft_printf(const char *, ...);

#endif

