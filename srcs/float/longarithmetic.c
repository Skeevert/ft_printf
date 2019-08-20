/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longarithmetic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 13:34:51 by svivienn          #+#    #+#             */
/*   Updated: 2019/08/12 16:32:51 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			normalize(t_long_value *x)
{
	unsigned long long int i;

	i = -1;
	while (++i < x->size)
	{
		if (x->value[i] >= 10)
		{
			x->value[i + 1] += x->value[i] / 10;
			x->value[i] %= 10;
		}
	}
	while (x->value[x->size - 1] == 0)
		x->size--;
}

int			sum(t_long_value *a, t_long_value *b)
{
	unsigned long long int	i;
	int						*s;

	if ((s = (int*)malloc(sizeof(int) * ((a->size > b->size) ? a->size + 1 :
		b->size + 1))) == NULL)
		return (0);
	memset(s, 0, sizeof(int) * (a->size > b->size ? a->size + 1 : b->size + 1));//поменять на ft_memset
	i = -1;
	while (++i < a->size)
		s[i] = a->value[i];
	i = -1;
	while (++i < b->size)
		s[i] += b->value[i];
	free(a->value);
	a->value = s;
	a->size = a->size > b->size ? a->size + 1 : b->size + 1;
	normalize(a);
	return (1);
}

int			simplecom(t_long_value *a, t_long_value *b)
{
	int						*rez;
	unsigned long long int	i;
	unsigned long long int	j;

	if ((rez = (int*)malloc(sizeof(int) * (a->size + b->size))) == NULL)
		return (0);
	memset(rez, 0, sizeof(*rez) * (a->size + b->size));//поменять на ft_memset
	i = -1;
	while (++i < a->size)
	{
		j = -1;
		while (++j < b->size)
		{
			rez[i + j] += a->value[i] * b->value[j];
		}
	}
	free(a->value);
	a->value = rez;
	a->size = (a->size + b->size);
	normalize(a);
	return (1);
}

int			initbinpow(t_long_value **rez, t_long_value **pow, int base)
{
	if ((*rez = (t_long_value*)malloc(sizeof(**rez))) == NULL)
		return (0);
	if (((*rez)->value = (int*)malloc(sizeof(int))) == NULL)
	{
		free(*rez);
		return (0);
	}
	if ((*pow = (t_long_value*)malloc(sizeof(**pow))) == NULL)
	{
		free_long_value(rez);
		return (0);
	}
	if (((*pow)->value = (int*)malloc(sizeof(int))) == NULL)
	{
		free_long_value(rez);
		free(pow);
		return (0);
	}
	(*rez)->value[0] = 1;
	(*rez)->size = 1;
	(*pow)->value[0] = base;
	(*pow)->size = 1;
	return (1);
}

t_long_value	*binpow(int n, int base)
{
	t_long_value	*rez;
	t_long_value	*pow;

	if (!initbinpow(&rez, &pow, base))
		return (NULL);
	while (n)
	{
		if (n & 1)
			if (!simplecom(rez, pow))//оптимизейшн
			{
				free_long_value(&rez);
				free_long_value(&pow);
				return (NULL);
			}
		if (!simplecom(pow, pow))//оптимизейшн
		{
			free_long_value(&rez);
			free_long_value(&pow);
			return (NULL);
		}
		n >>= 1;
	}
	free_long_value(&pow);
	return (rez);
}
