/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writefloat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boris <boris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:48:11 by boris             #+#    #+#             */
/*   Updated: 2019/08/21 21:28:50 by boris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "main.h"

t_long_value	*whole(int n)
{
	t_long_value	*rez;
	t_long_value	*rezerv;
	int				j;

	if (!(rez = binpow(n, 2)))
		return (NULL);
	j = 52;
	while (--n >= 0 && --j >= 0)
		if (d.i >> j & 1)
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

int				normrez(t_long_value **x, int pow)
{
	int				i;
	int				*rez;
	t_long_value	*rezerv;

	if ((rez = (int*)malloc(sizeof(int) * pow)) == NULL)
		return (0);
	ft_memset(rez, 0, sizeof(int) * pow);
	i = 0;
	while (++i && pow - i >= 0 && (*x)->size - i + 1 > 0)
		rez[pow - i] = (*x)->value[(*x)->size - i];
	free((*x)->value);
	(*x)->value = rez;
	(*x)->size = pow;
	if (!(rezerv = binpow(pow, 5)))
		return (0);
	if (!(sum(*x, rezerv)))
	{
		free_long_value(&rezerv);
		return (0);
	}
	(*x)->size = pow;
	free_long_value(&rezerv);
	return (1);
}

t_long_value	*fraction(int ot, int pow, int status)
{
	t_long_value	*rez;
	int				j;

	if (!initlwhole(&rez))
		return (NULL);
	if (status)
		if (!normrez(&rez, pow))
		{
			free_long_value(&rez);
			return (NULL);
		}
	pow += status ? 1 : 0;
	j = 52 - ot;
	while (--j >= 0)
	{
		if (d.i >> j & 1)
			if (!normrez(&rez, pow))
			{
				free_long_value(&rez);
				return (NULL);
			}
		pow++;
	}
	return (rez);
}

char			*wholetostr(t_long_value *wh)
{
	char					*str;
	unsigned long long int	i;

	if (!(str = (char*)malloc(sizeof(char) * (wh->size + 1))))
		return (NULL);
	i = -1;
	while (++i < wh->size)
		str[i] = wh->value[wh->size - i - 1] + '0';
	str[i] = '\0';
	return (str);
}

char			*doubletonumber(t_long_value *wh, t_long_value *frc, int prec)
{
	char		*str1;
	char		*str2;

	if (!(str1 = (char*)malloc(sizeof(char) * (wh->size + frc->size + 2))))
		return (NULL);
	str1[0] = '\0';
	if (!(str2 = wholetostr(wh)))
	{
		free(str1);
		return (NULL);
	}
	ft_strcat(str1, str2);
	free(str2);
	if (prec != 0)
	{
		ft_strcat(str1, ".");
		if (!(str2 = wholetostr(frc)))
		{
			free(str1);
			return (NULL);
		}
		ft_strcat(str1, str2);
		free(str2);
	}
	return (str1);
}
