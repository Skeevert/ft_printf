/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 11:47:44 by hshawand          #+#    #+#             */
/*   Updated: 2019/08/22 14:51:46 by hshawand         ###   ########.fr       */
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

void	ft_preformat_p(t_format *c_format, char *str)
{
	char			to_add[3];
	size_t			len;

	ft_strcpy(to_add, "0x");
	len = ft_strlen(str) + ft_strlen(to_add);
	if (c_format->flag & 0x04)
	{
		gwrite(1, to_add, ft_strlen(to_add));
		c_format->prec ? ft_putnchar('0', c_format->prec) : 0;
		gwrite(1, str, ft_strlen(str));
		c_format->width > len ? ft_putnchar(' ', c_format->width - len) : 0;
	}
	else
	{
		!(c_format->flag & 0x08) && c_format->width > len ?
			ft_putnchar(' ', c_format->width - len) : 0;
		gwrite(1, to_add, ft_strlen(to_add));
		c_format->flag & 0x08 && c_format->width > len ?
			ft_putnchar('0', c_format->width - len) : 0;
		c_format->prec ? ft_putnchar('0', c_format->prec) : 0;
		gwrite(1, str, ft_strlen(str));
	}
}

void	ft_print_p(t_format *c_fmt, void *ptr)
{
	uintptr_t		ptr_addr;
	char			output[23];
	unsigned int	len;

	ptr_addr = (uintptr_t)ptr;
	ft_utoa64_base(ptr_addr, output, 16, 0);
	len = ft_strlen(output);
	ptr_addr ? 0 : ft_zero_zero(c_fmt, output, 16);
	c_fmt->prec ? (c_fmt->flag &= ~0x08) : 0;
	c_fmt->prec = c_fmt->prec > len ? c_fmt->prec - len : 0;
	c_fmt->width = c_fmt->width < c_fmt->prec ?
		c_fmt->prec : c_fmt->width;
	c_fmt->prec ? c_fmt->width -= c_fmt->prec : 0;
	ft_preformat_p(c_fmt, output);
}
