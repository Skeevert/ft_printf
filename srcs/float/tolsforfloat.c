/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tolsforfloat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 20:14:40 by boris             #+#    #+#             */
/*   Updated: 2019/08/12 16:45:36 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		dexp(void)
{
	int i;

	i = ((d.i >> 52) & 2047) - 1023;
	return (i);
}

int		longdexp(void)
{
	int i;

	i = (ld.i[2] & 32767) - 16383;
	return (i);
}

void	free_long_value(t_long_value **x)
{
	free((*x)->value);
	free(*x);
}

char	*doubletostr(int prec)
{
	t_long_value	*wh;
	t_long_value	*frc;
	char			*str;

	if (dexp() >= 0)
	{
		wh = whole(dexp());
		frc = fraction(dexp(), 1);
	}
	else
	{
		if (!initlwhole(&wh))
			return (NULL);
		frc = fraction(0, -(dexp()));
	}
	if (!normnumber(&wh, &frc, prec))
		return (NULL);
	if (!(str = doubletonumber(wh, frc, prec)))
		return (freenumber(&wh, &frc));
	free_long_value(&wh);
	free_long_value(&frc);
	return (str);
}

int		zerotofrc(t_long_value *frc, int prec)
{
	int						*rez;
	unsigned long long int	i;

	if ((rez = (int*)malloc(sizeof(int) * prec)) == NULL)
		return (0);
	memset(rez, 0, sizeof(int) * prec);
	i = -1;
	while (++i < frc->size)
		rez[prec - frc->size + i] = frc->value[i];
	free(frc->value);
	frc->value = rez;
	frc->size = prec;
	return (1);
}
