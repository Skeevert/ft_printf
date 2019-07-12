/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diouxX.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 15:09:05 by hshawand          #+#    #+#             */
/*   Updated: 2019/07/12 13:11:19 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* Also call ft_print_d for %i */
/* We also need ft_int64_uitoa */

void	ft_print_d(t_format *c_format, int64_t d)
{
	char	output[20];

	if (c_format->length == 5)
		/* just ft_int64_itoa */
		ft_itoa64(d, output);
	else if (c_format->length == 4)
		/* ft_int64_itoa recast to long long */
		ft_itoa64((long long)d, output);
	else if (c_format->length == 3)
		/* ft_int64_itoa recast to long */
		ft_itoa64((long)d, output);
	else if (c_format->length == 2)
		/* ft_int64_itoa recast to short */
		ft_itoa64((short)d, output);
	else if (c_format->length == 1)
		/* ft_int64_itoa recast to char */
		ft_itoa64((char)d, output);
	else if (c_format->length == 0)
		/* ft_int64_itoa recast to int */
		ft_itoa64((int)d, output);
	ft_print_s(c_format, output);
}
