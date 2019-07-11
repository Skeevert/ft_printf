/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_arithmetic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:51:36 by hshawand          #+#    #+#             */
/*   Updated: 2019/06/07 13:18:47 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static void	ft_long_multiply(char *num, unsigned int mul, int pres)
{
	int cache;
	int i;

	if (mul > 9)
		return ;
	i = pres - 1;
	cache = 0;
	while (i >= 0)
	{
		cache = (num[i + 1] - '0') * mul + cache;
		num[i + 1] = cache % 10 + '0';
		cache = cache / 10;
		i--;
	}
	num[0] = cache + '0';
}

static void	ft_long_sum2(char *num0, char *num1, int pres)
{
	int	cache;
	int	i;

	i = pres - 1;
	cache = 0;
	while (i >= 0)
	{
		cache = num0[i + 1] - '0' + num1[i] - '0' + cache;
		num0[i + 1] = cache % 10 + '0';
		cache = cache / 10;
		i--;
	}
	num0[0] = cache + '0';
}

static void	ft_mul_10(char *num, int pres)
{
	int i;

	i = 0;
	while (i < pres)
	{
		num[i] = num[i + 1];
		i++;
	}
	num[i] = '0';
}

int				main()
{
	char	n0[25] = "000000000000000000009999\0"; /* Adaptation for sum2 */
	char	n1[24] = "00000000000000000999999\0";

	ft_long_multiply(n0, 5, 23);
	ft_mul_10(n0, 23);
	printf("%s\n", n0);
	return (0);
}