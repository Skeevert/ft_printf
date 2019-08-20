/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writelongdouble.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:51:08 by svivienn          #+#    #+#             */
/*   Updated: 2019/08/12 17:13:17 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				initlwhole(t_long_value **rez)
{
	if ((*rez = (t_long_value*)malloc(sizeof(*rez))) == NULL)
		return (0);
	if (((*rez)->value = (int*)malloc(sizeof(int))) == NULL)
	{
		free(rez);
		return (0);
	}
	(*rez)->value[0] = 0;
	(*rez)->size = 1;
	return (1);
}

t_long_value	*lwhole(int n)
{
	t_long_value	*rez;
	t_long_value	*rezerv;
	int				j;

	if (!initlwhole(&rez))
		return (0);
	j = 64;
	n++;
	while (--j >= 0 && --n >= 0)
		if (ld.man >> j & 1)
		{
			if (!(rezerv = binpow(n, 2)))
			{
				free_long_value(&rez);
				return (NULL);
			}
			if (!(sum(rez, rezerv)))
			{
				free_long_value(&rez);
				free_long_value(&rezerv);
				return (NULL);
			}
			free_long_value(&rezerv);
		}
	return (rez);
}

t_long_value	*lfraction(int ot, int pow)
{
	t_long_value	*rez;
	int				j;

	if (!initlwhole(&rez))
		return (0);
	j = 64 - ot - 1;
	while (--j >= 0)
	{
		if (ld.man >> j & 1)
			if (!normrez(&rez, pow))
			{
				free_long_value(&rez);
				return (NULL);
			}
		pow++;
	}
	return (rez);
}

char			*ldoubletostr(int prec)
{
	t_long_value	*wh;
	t_long_value	*frc;
	char			*str;

	if (longdexp() >= 0)
	{
		wh = lwhole(longdexp());
		frc = lfraction(longdexp(), 1);
	}
	else
	{
		if (!initlwhole(&wh))
			return (NULL);
		frc = lfraction(0, -(longdexp()));
	}
	if (!normnumber(&wh, &frc, prec))
		return (NULL);
	if (!(str = doubletonumber(wh, frc, prec)))
		return (freenumber(&wh, &frc));
	free_long_value(&wh);
	free_long_value(&frc);
	return (str);
}

int				finalprintnahoild(t_format *inf)
{
	char *str;

	if (ld.ld != ld.ld)
		write(1, "nan", 3);
	else if (ld.man == 0 && (ld.i[2] == 32767 || ld.i[2] == 65535))
		lfiksfinal();
	else if (ld.man == 0 && (ld.i[2] == 0 || ld.i[2] == 32768))
	{
		if (!(str = zerostr(inf->prec)))
			return (0);
		printnumber(inf, str, (int)(d.d < 0), (int)(d.d < 0 ||
			inf->flag & 1 || inf->flag >> 1 & 1));
		free(str);
	}
	else
	{
		if (!(str = ldoubletostr(inf->prec)))
			return (0);
		printnumber(inf, str, (int)(ld.ld < 0), (int)(d.d < 0 ||
			inf->flag & 1 || inf->flag >> 1 & 1));
		free(str);
	}
	return (1);
}
