/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diouxX.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 15:09:05 by hshawand          #+#    #+#             */
/*   Updated: 2019/07/12 16:04:44 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* Also call ft_print_d for %i */
/* We also need ft_int64_uitoa */
/* NEGATIVE VALUE ACHTUNG! -0010 VS 00-10! ALSO ADD flag, that change minus to smth */
void	ft_preformat_0(t_format *c_format, char base, char mode, char *str) /* WORKS ONLY WITH 0*/
{
	char			to_add[3];
	unsigned int	len;

	base == 8 ? (int)(ft_strcpy(to_add, "0")) : (to_add[0] = 0);
	base == 16 && mode == 0 ? (ft_strcpy(to_add, "0x")) : 0;
	base == 16 && mode == 1 ? (ft_strcpy(to_add, "0X")) : 0;
	c_format->flag & 0x10 ? len = ft_strlen(str) + ft_strlen(to_add) :
		(len = ft_strlen(str));
	if (c_format->flag & 0x04)
	{
		c_format->flag & 0x10 ? ft_putstr(to_add) : 0;
		c_format->prec ? ft_putnchar('0', c_format->prec - ft_strlen(str)) : 0;
		ft_putstr(str);
		c_format->width > len ? ft_putnchar(' ', c_format->width - len) : 0;
	}
	else
	{
		!(c_format->flag & 0x08)  && c_format->width > len ? 
			ft_putnchar(' ', c_format->width - len) : 0;
		c_format->flag & 0x10 ? ft_putstr(to_add) : 0;
		c_format-> flag & 0x08 && c_format->width > len ?
			ft_putnchar('0', c_format->width - len) : 0;
		c_format->prec ? ft_putnchar('0', c_format->prec - ft_strlen(str)) : 0;
		ft_putstr(str);
	}
}

void	ft_print_d(t_format *c_format, int64_t d)
{
	char	output[21];

	if (c_format->length == 5)
		ft_itoa64(d, output);
	else if (c_format->length == 4)
		ft_itoa64((long long)d, output);
	else if (c_format->length == 3)
		ft_itoa64((long)d, output);
	else if (c_format->length == 2)
		ft_itoa64((short)d, output);
	else if (c_format->length == 1)
		ft_itoa64((char)d, output);
	else if (c_format->length == 0)
		ft_itoa64((int)d, output);
	ft_print_s(c_format, output);
}

/* TODO: add '#' flag process: '0' for %o, '0x' for %x, 0X for %X */

void	ft_print_oxX(t_format *c_format, uint64_t d, char base, char mode)
{
	char			output[23];
	unsigned int	len;	

	if (c_format->length == 5)
		ft_utoa64_base(d, output, base, mode);
	else if (c_format->length == 4)
		ft_utoa64_base((unsigned long long)d, output, base, mode);
	else if (c_format->length == 3)
		ft_utoa64_base((unsigned long)d, output, base, mode);
	else if (c_format->length == 2)
		ft_utoa64_base((unsigned short)d, output, base, mode);
	else if (c_format->length == 1)
		ft_utoa64_base((unsigned char)d, output, base, mode);
	else if (c_format->length == 0)
		ft_utoa64_base((unsigned int)d, output, base, mode);
	len = ft_strlen(output);
	c_format->prec ? (c_format->flag &= ~0x08) : 0;
	c_format->prec > len ? (c_format->width -= (c_format->prec - len)) :
		(c_format->prec = 0);
	ft_preformat_0(c_format, base, mode, output);
}
