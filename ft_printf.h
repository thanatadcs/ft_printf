/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 02:23:46 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/10 17:34:26 by tanukool         ###   ########.fr       */
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

int	ft_putchar(void *data);
int	ft_putstr(void *data);
int	ft_putnbr(void *data);
int	ft_puthex_lower(void *data);
int	ft_puthex_upper(void *data);
int	ft_printf(const char *, ...);

#endif

