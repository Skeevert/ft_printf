/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 11:47:44 by hshawand          #+#    #+#             */
/*   Updated: 2019/07/15 14:02:56 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
/*
void	ft_print_c(t_format *c_format, char c)
{
	char	to_print[STACKSIZE];

	to_print[c_format->width] = 0;
	if (c_format->width && !(c_format->flag & 0x04))
	{
		to_print[c_format->width - 1] = c;
		if (c_format->flag & 0x08)
			ft_memset(to_print, '0', c_format->width - 1);
		else
			ft_memset(to_print, ' ', c_format->width - 1);
		ft_putstr(to_print);
	}
	else if (c_format->width)
	{
		to_print[0] = c;
		ft_memset(to_print + 1, ' ', c_format->width - 1);
		ft_putstr(to_print);
	}
	else
		write(1, &c, 1);
}
*/

void	ft_print_c(t_format *c_format, char c)
{
	char filler;

	c_format->flag & 0x08 ? (filler = '0') : (filler = ' ');
	if (c_format->flag & 0x04)
	{
		write(1, &c, 1);
		c_format->width > 1 ? ft_putnchar(filler, c_format->width - 1) : 0;
	}
	else
	{
		c_format->width > 1 ? ft_putnchar(' ', c_format->width - 1) : 0;
		write(1, &c, 1);
	}
}
/*
void	ft_print_s(t_format *c_format, char *str)
{
	char	to_print[STACKSIZE];
	int		start;

	to_print[c_format->width] = 0;
	start = c_format->width - ft_strlen(str);
	if (start < 0)
		start = 0;
	if (c_format->width && !(c_format->flag & 0x04))
	{
		if (c_format->flag & 0x08)
			ft_memset(to_print, '0', c_format->width);
		else
			ft_memset(to_print, ' ', c_format->width);
		ft_strcpy(to_print + start, str);
		ft_putstr(to_print);
	}
	else if (c_format->width)
	{
		ft_strcpy(to_print, str);
		ft_memset(to_print + ft_strlen(str), ' ', start);
		ft_putstr(to_print);
	}
	else
		ft_putstr(str);
}
*/

void	ft_print_s(t_format *c_format, char *str)
{
	char			filler;
	unsigned int	len;

	c_format->flag & 0x08 ? (filler = '0') : (filler = ' ');
	len = ft_strlen(str);
	if (c_format->flag & 0x04)
	{
		write(1, str, len);
		c_format->width > len ? ft_putnchar(' ', c_format->width - len) : 0;
	}
	else
	{
		c_format->width > len ? ft_putnchar(filler, c_format->width - len) : 0;
		write(1, str, len);
	}
}

void	ft_print_p(t_format *c_format, void *ptr)
{
	uintptr_t		ptr_addr;
	char			output[23];

	ptr_addr = (uintptr_t)ptr;
	if (c_format->flag & 0x08)
	{
		write(1, "0x", 2);
		c_format->width >= 2 ? c_format->width -= 2 : 0;
		ft_utoa64_base(ptr_addr, output, 16, 0);
	}
	else
	{
		output[0] = '0';
		output[1] = 'x';
		ft_utoa64_base(ptr_addr, output + 2, 16, 0);
	}
	ft_print_s(c_format, output);
}
