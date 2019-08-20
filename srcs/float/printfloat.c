/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfloat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 23:58:56 by svivienn          #+#    #+#             */
/*   Updated: 2019/08/20 13:34:12 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		formfraction(size_t prec, t_long_value *frc)
{
	unsigned long long int i;

	if (frc->size > prec)
	{
		i = -1;
		while ((++i + 1) < frc->size && frc->size - i > prec)
			if (frc->value[i] < 5)
				frc->value[i] = -1;
			else if (frc->value[i] > 5)
			{
				frc->value[i] = -1;
				frc->value[i + 1] += 1;
			}
			else
			{
				frc->value[i] = -1;
				frc->value[i + 1] += frc->value[i + 1] % 2;
			}
		if (!normfraction(frc))
			return (0);
	}
	else if (!zerotofrc(frc, prec))
		return (0);
	return (1);
}

int		normfraction(t_long_value *frc)
{
	unsigned long long	i;
	int					*rez;
	unsigned long long	j;

	i = 0;
	while (frc->value[i] == -1)
		i++;
	j = i - 1;
	while (++j < frc->size - 1 && frc->value[j] >= 10)
	{
		frc->value[j + 1] += frc->value[j] / 10;
		frc->value[j] = frc->value[j] % 10;
	}
	if ((rez = (int*)malloc(sizeof(int) * frc->size - i)) == NULL)
		return (0);
	j = -1;
	while (i + (++j) < frc->size)
		rez[j] = frc->value[i + j];
	free(frc->value);
	frc->value = rez;
	frc->size = frc->size - i;
	return (1);
}

int		normwhole(t_long_value *wh, int plus)
{
	unsigned long long int	i;
	int						*rez;

	wh->value[0] += plus;
	i = -1;
	while (wh->value[++i] == 10 && i < wh->size - 1)
	{
		wh->value[i] = 0;
		wh->value[i + 1]++;
	}
	if (wh->value[wh->size - 1] == 10)
	{
		if ((rez = (int*)malloc(sizeof(int) * (wh->size + 1))) == NULL)
			return (0);
		memcpy(rez, wh->value, sizeof(int) * wh->size - 1);//поменять на ft
		rez[wh->size - 1] = 0;
		rez[wh->size] = 1;
		free(wh->value);
		wh->value = rez;
		wh->size++;
	}
	return (1);
}

char	*freenumber(t_long_value **wh, t_long_value **frc)
{
	free_long_value(wh);
	free_long_value(frc);
	return (NULL);
}

int		normnumber(t_long_value **wh, t_long_value **frc, int prec)
{
	if (!formfraction(prec, *frc))
	{
		free_long_value(wh);
		free_long_value(frc);
		return (0);
	}
	if ((*frc)->value[(*frc)->size - 1] == 10 || (prec == 0 &&
		(*frc)->value[(*frc)->size - 1] > 5))
	{
		(*frc)->value[(*frc)->size - 1] = 0;
		if (!normwhole(*wh, 1))
		{
			free_long_value(wh);
			free_long_value(frc);
			return (0);
		}
	}
	else if ((prec == 0 && (*frc)->value[(*frc)->size - 1] == 5))
		if (!normwhole(*wh, (*wh)->value[(*wh)->size - 1] % 2))
		{
			free_long_value(wh);
			free_long_value(frc);
			return (0);
		}
	return (1);
}
