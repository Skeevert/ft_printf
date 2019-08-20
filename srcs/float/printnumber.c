/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 07:58:43 by svivienn          #+#    #+#             */
/*   Updated: 2019/08/12 16:51:08 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printnumber(t_format *inf, char *str, int zn, int zap)
{
	if (inf->width <= strlen(str) + zap || inf->flag >> 2 & 1)
	{
		preprint(zn, inf);
		write(1, str, strlen(str));
		(inf->flag >> 4 & 1 && inf->prec == 0) ? write(1, ".", 1) : 0;
		printspase(' ', inf->width - strlen(str) - zap);
	}
	else if (inf->flag >> 3 & 1)
	{
		preprint(zn, inf);
		printspase('0', inf->width - strlen(str) - zap);
		write(1, str, strlen(str));
	}
	else
	{
		printspase(' ', inf->width - strlen(str) - zap);
		preprint(zn, inf);
		write(1, str, strlen(str));
	}
	(inf->flag >> 4 & 1 && inf->prec == 0 && (!(inf->flag >> 2 & 1))) ?
		write(1, ".", 1) : 0;
}

void	preprint(int zn, t_format *inf)
{
	if (zn)
		write(1, "-", 1);
	else if (inf->flag >> 1 & 1)
		write(1, "+", 1);
	else if (inf->flag & 1)
		write(1, " ", 1);
}

void	printspase(char c, int i)
{
	while (i > 0)
	{
		write(1, &c, 1);
		i--;
	}
}

char	*zerostr(int prec)
{
	char	*rez;

	if ((rez = (char*)malloc(sizeof(char) * (prec + 2))))
	{
		memset(rez, '0', sizeof(char) * (prec + 3));
		rez[1] = '.';
		rez[prec + 2] = '\0';
	}
	return (rez);
}

int		finalprintnahoid(t_format *inf)
{
	char *str;

	if (d.d != d.d)
		write(1, "nan", 3);
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
