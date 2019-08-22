/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 11:47:44 by hshawand          #+#    #+#             */
/*   Updated: 2019/08/22 11:52:07 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_print_c(t_format *c_format, char c)
{
	char filler;

	c_format->flag & 0x08 ? (filler = '0') :
		(filler = ' ');
	if (c_format->flag & 0x04)
	{
		gwrite(1, &c, 1);
		c_format->width > 1 ? ft_putnchar(filler, c_format->width - 1) : 0;
	}
	else
	{
		c_format->width > 1 ? ft_putnchar(' ', c_format->width - 1) : 0;
		gwrite(1, &c, 1);
	}
}

void	ft_print_s(t_format *c_format, char *str)
{
	char			filler;
	unsigned int	len;
	if (!str)
	{
		ft_print_s(c_format, "(null)");
		return ;
	}
	c_format->flag & 0x08 ? (filler = '0') :
		(filler = ' ');
	len = ft_strlen(str);
	c_format->prec_set && len > c_format->prec ? (len = c_format->prec) : 0;
	if (c_format->flag & 0x04)
	{
		gwrite(1, str, len);
		c_format->width > len ? ft_putnchar(' ', c_format->width - len) : 0;
	}
	else
	{
		c_format->width > len ? ft_putnchar(filler, c_format->width - len) : 0;
		gwrite(1, str, len);
	}
}

void	ft_print_p(t_format *c_format, void *ptr)
{
	uintptr_t		ptr_addr;
	char			output[23];

	ptr_addr = (uintptr_t)ptr;
	if (c_format->flag & 0x08)
	{
		gwrite(1, "0x", 2);
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
