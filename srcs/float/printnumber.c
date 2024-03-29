/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 07:58:43 by svivienn          #+#    #+#             */
/*   Updated: 2019/08/22 09:20:41 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "main.h"

void	printnumber(t_format *inf, char *str, int zn, int zap)
{
	if (inf->width <= ft_strlen(str) + zap || inf->flag >> 2 & 1)
	{
		preprint(zn, inf);
		gwrite(1, str, ft_strlen(str));
		(inf->flag >> 4 & 1 && inf->prec == 0) ? write(1, ".", 1) : 0;
		printspase(' ', inf->width - ft_strlen(str) - zap);
	}
	else if (inf->flag >> 3 & 1)
	{
		preprint(zn, inf);
		printspase('0', inf->width - ft_strlen(str) - zap);
		gwrite(1, str, ft_strlen(str));
	}
	else
	{
		printspase(' ', inf->width - ft_strlen(str) - zap);
		preprint(zn, inf);
		gwrite(1, str, ft_strlen(str));
	}
	(inf->flag >> 4 & 1 && inf->prec == 0 && (!(inf->flag >> 2 & 1))) ?
		gwrite(1, ".", 1) : 0;
}

void	preprint(int zn, t_format *inf)
{
	if (zn)
		gwrite(1, "-", 1);
	else if (inf->flag >> 1 & 1)
		gwrite(1, "+", 1);
	else if (inf->flag & 1)
		gwrite(1, " ", 1);
}

void	printspase(char c, int i)
{
	while (i > 0)
	{
		gwrite(1, &c, 1);
		i--;
	}
}

char	*zerostr(int prec)
{
	char	*rez;

	if ((rez = (char*)malloc(sizeof(char) * (prec + 2))))
	{
		ft_memset(rez, '0', sizeof(char) * (prec + 3));
		rez[1] = '.';
		rez[prec + 2] = '\0';
	}
	return (rez);
}

int		finalprintnahoid(t_format *inf)
{
	char *str;

	if (d.d != d.d)
		gwrite(1, "nan", 3);
	else if (d.i == 0x7FF0000000000000 || d.i == 0xFFF0000000000000)
		fiksfinal();
	else if (d.i == 0 || d.i == 0x8000000000000000)
	{
		if (!(str = zerostr(inf->prec)))
			return (0);
		printnumber(inf, str, (int)(d.d < 0), (int)(d.d < 0 ||
			inf->flag & 1 || inf->flag >> 1 & 1));
		free(str);
	}
	else
	{
		if (!(str = doubletostr(inf->prec)))
			return (0);
		printnumber(inf, str, (int)(d.d < 0), (int)(d.d < 0 ||
			inf->flag & 1 || inf->flag >> 1 & 1));
		free(str);
	}
	return (1);
}
