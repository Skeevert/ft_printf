/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa64.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 15:47:23 by svivienn          #+#    #+#             */
/*   Updated: 2019/08/19 12:55:00 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdint.h>
#include <stdlib.h>

void	ft_itoa64(int64_t c, char *str, t_format *c_fmt)
{
	int			size;
	uint64_t	u_save;

	size = 1;
	c < 0 ? (u_save = -c) :
		(u_save = c);
	c_fmt->sign = c < 0 ? 1 : 0;
	while (u_save > 1)
	{
		u_save /= 10;
		size++;
	}
	str[0] = '0';
	str[size] = '\0';
	c < 0 ? (u_save = -c) :
		(u_save = c);
	while (u_save != 0)
	{
		str[size - 1] = (u_save % 10) + '0';
		size--;
		u_save /= 10;
	}
}

void	ft_utoa64_base(uint64_t c, char *str, char base, char mode)
{
	int				size;
	uint64_t		u_save;
	static char		mode_0[] = "0123456789abcdef";
	static char		mode_1[] = "0123456789ABCDEF";

	size = 1;
	u_save = c;
	while (c > 1)
	{
		c /= base;
		size++;
	}
	str[0] = '0';
	str[size] = '\0';
	while (u_save != 0)
	{
		if (!mode)
			str[size - 1] = mode_0[u_save % base];
		else
			str[size - 1] = mode_1[u_save % base];
		size--;
		u_save /= base;
	}
}
