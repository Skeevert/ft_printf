/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diouxx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 15:09:05 by hshawand          #+#    #+#             */
/*   Updated: 2019/08/22 13:18:28 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_zero_zero(t_format *c_fmt, char *str, char base)
{
	if (c_fmt->prec_set && !(c_fmt->prec))
	{
		if (base == 8 && c_fmt->flag & 0x10)
			ft_strcpy(str, "0");
		else
			ft_strcpy(str, "");
	}
	c_fmt->flag &= ~0x10;
}

void	ft_preformat_di(t_format *c_fmt, size_t len, char *str)
{
	char	to_add;

	c_fmt->sign ? (to_add = '-') :
		(to_add = 0);
	!(c_fmt->sign) && c_fmt->flag & 0x01 ? (to_add = ' ') : 0;
	!(c_fmt->sign) && c_fmt->flag & 0x02 ? (to_add = '+') : 0;
	c_fmt->prec ? c_fmt->width -= c_fmt->prec : 0;
	if (c_fmt->flag & 0x04)
	{
		to_add ? gwrite(1, &to_add, 1) : 0;
		c_fmt->prec ? ft_putnchar('0', c_fmt->prec) : 0;
		gwrite(1, str, ft_strlen(str));
		c_fmt->width > len ? ft_putnchar(' ', c_fmt->width - len) : 0;
	}
	else
	{
		!(c_fmt->flag & 0x08) && c_fmt->width > len ?
			ft_putnchar(' ', c_fmt->width - len) : 0;
		to_add ? gwrite(1, &to_add, 1) : 0;
		c_fmt->flag & 0x08 && c_fmt->width > len ?
			ft_putnchar('0', c_fmt->width - len) : 0;
		c_fmt->prec ? ft_putnchar('0', c_fmt->prec) : 0;
		gwrite(1, str, ft_strlen(str));
	}
}

void	ft_preformat_ouxx(t_format *c_format, char base, char mode, char *str)
{
	char			to_add[3];
	size_t			len;

	base == 8 ? (int)(ft_strcpy(to_add, "0")) : (to_add[0] = 0);
	base == 16 && mode == 0 ? (ft_strcpy(to_add, "0x")) : 0;
	base == 16 && mode == 1 ? (ft_strcpy(to_add, "0X")) : 0;
	c_format->flag & 0x10 ? len = ft_strlen(str) + ft_strlen(to_add) :
		(len = ft_strlen(str));
	if (c_format->flag & 0x04)
	{
		c_format->flag & 0x10 ? gwrite(1, to_add, ft_strlen(to_add)) : 0;
		c_format->prec ? ft_putnchar('0', c_format->prec) : 0;
		gwrite(1, str, ft_strlen(str));
		c_format->width > len ? ft_putnchar(' ', c_format->width - len) : 0;
	}
	else
	{
		!(c_format->flag & 0x08) && c_format->width > len ?
			ft_putnchar(' ', c_format->width - len) : 0;
		c_format->flag & 0x10 ? gwrite(1, to_add, ft_strlen(to_add)) : 0;
		c_format->flag & 0x08 && c_format->width > len ?
			ft_putnchar('0', c_format->width - len) : 0;
		c_format->prec ? ft_putnchar('0', c_format->prec) : 0;
		gwrite(1, str, ft_strlen(str));
	}
}

void	ft_print_d(t_format *c_fmt, int64_t d)
{
	char			output[21];
	size_t			len;

	if (c_fmt->length == 5)
		ft_itoa64(d, output, c_fmt);
	else if (c_fmt->length == 4)
		ft_itoa64((long long)d, output, c_fmt);
	else if (c_fmt->length == 3)
		ft_itoa64((long)d, output, c_fmt);
	else if (c_fmt->length == 2)
		ft_itoa64((short)d, output, c_fmt);
	else if (c_fmt->length == 1)
		ft_itoa64((char)d, output, c_fmt);
	else if (c_fmt->length == 0)
		ft_itoa64((int)d, output, c_fmt);
	d ? 0 : ft_zero_zero(c_fmt, output, 10);
	len = ft_strlen(output);
	c_fmt->prec ? (c_fmt->flag &= ~0x08) : 0;
	c_fmt->prec = c_fmt->prec > len ? c_fmt->prec - len : 0;
	c_fmt->sign || (c_fmt->flag & 0x03) ? (len++) : 0;
	c_fmt->width = c_fmt->width < c_fmt->prec ?
		c_fmt->prec : c_fmt->width;
	ft_preformat_di(c_fmt, len, output);
}

void	ft_print_ouxx(t_format *c_fmt, uint64_t d, char base, char mode)
{
	char			output[23];
	unsigned int	len;

	if (c_fmt->length == 5)
		ft_utoa64_base(d, output, base, mode);
	else if (c_fmt->length == 4)
		ft_utoa64_base((unsigned long long)d, output, base, mode);
	else if (c_fmt->length == 3)
		ft_utoa64_base((unsigned long)d, output, base, mode);
	else if (c_fmt->length == 2)
		ft_utoa64_base((unsigned short)d, output, base, mode);
	else if (c_fmt->length == 1)
		ft_utoa64_base((unsigned char)d, output, base, mode);
	else if (c_fmt->length == 0)
		ft_utoa64_base((unsigned int)d, output, base, mode);
	len = ft_strlen(output);
	d ? 0 : ft_zero_zero(c_fmt, output, base);
	c_fmt->prec ? (c_fmt->flag &= ~0x08) : 0;
	c_fmt->prec = c_fmt->prec > len ? c_fmt->prec - len : 0;
	c_fmt->width = c_fmt->width < c_fmt->prec ?
		c_fmt->prec : c_fmt->width;
	c_fmt->prec ? c_fmt->width -= c_fmt->prec : 0;
	ft_preformat_ouxx(c_fmt, base, mode, output);
}
