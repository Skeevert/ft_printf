/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prostonehvataetmesta.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 15:12:40 by svivienn          #+#    #+#             */
/*   Updated: 2019/08/12 17:14:40 by svivienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "main.h"

void	lfiksfinal(void)
{
	if (ld.i[2] == 32767)
		gwrite(1, "inf", 3);
	else
		gwrite(1, "-inf", 4);
}

void	fiksfinal(void)
{
	if (d.i == 0x7FF0000000000000)
		gwrite(1, "inf", 3);
	else
		gwrite(1, "-inf", 4);
}
