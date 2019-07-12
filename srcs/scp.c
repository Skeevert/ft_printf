/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 11:47:44 by hshawand          #+#    #+#             */
/*   Updated: 2019/07/12 14:19:53 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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

void	ft_print_p(t_format *c_format, void *ptr)
{
	uintptr_t		ptr_addr;
	static char		hex[] = "0123456789abcdef";
	uintptr_t		pow;
	char			output[15];
	int				i;

	ptr_addr = (uintptr_t)ptr;
	i = 2;
	output[0] = '0';
	output[1] = 'x';
	output[14] = 0;
	pow = 1;
	while (ptr_addr / pow / 16 > 0)
		pow *= 16;
	while (pow >= 1)
	{
		output[i] = *(hex + (ptr_addr / pow % 16));
		pow /= 16;
		i++;
	}
	ft_print_s(c_format, output);
}
