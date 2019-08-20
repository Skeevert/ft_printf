/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <[hshawand@student.42.fr]>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 13:13:28 by hshawand          #+#    #+#             */
/*   Updated: 2019/08/20 13:27:52 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "ft_printf.h"

void	ft_print_f(t_format *c_fmt, va_list args)
{
	c_fmt->prec = c_fmt->prec_set ? c_fmt->prec : 6;
	if (c_fmt->length == 5)
	{
		ld.ld = va_arg(args, long double);
		finalprintnahoild(c_fmt);
	}
	else
	{
		d.d = va_arg(args, double);
		finalprintnahoid(c_fmt);
	}
}
