/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:42:41 by hshawand          #+#    #+#             */
/*   Updated: 2019/08/12 13:41:14 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
 * # 0 - + and space
 * '-' -- Left-align the output of this placeholder. (The default is to right-align the output.)
 * '+' -- Prepends a plus for positive signed-numeric types. positive = +, negative = -. (The default doesn't prepend anything in front of positive numbers.)
 * ' ' -- Prepends a space for positive signed-numeric types. positive =  , negative = -. This flag is ignored if the + flag exists. (The default doesn't prepend anything in front of positive numbers.)
 * '0' -- When the 'width' option is specified, prepends zeros for numeric types. (The default prepends spaces.) For example, printf("%2X",3) produces  3, while printf("%04X",3) produces in 0003.
 * '#' -- Alternate form: For g and G types, trailing zeros are not removed. For f, F, e, E, g, G types, the output always contains a decimal point. For o, x, X types, the text 0, 0x, 0X, respectively, is prepended to non-zero numbers.
 */

 /*
  * diouxX with the following flags: hh, h, l and ll
  * f with the following flags: l and L
  * %%
  */

void	ft_struct_process(t_format *c_format, va_list args)
{
	if (c_format->type == 'c')
		ft_print_c(c_format, va_arg(args, int));
	else if (c_format->type == 's')
		ft_print_s(c_format, va_arg(args, char *));
	else if (c_format->type == 'p')
		ft_print_p(c_format, va_arg(args, void *));
	else if (c_format->type == 'd' || c_format->type == 'i')
		ft_print_d(c_format, va_arg(args, int64_t));
	else if (c_format->type == 'o')
		ft_print_ouxX(c_format, va_arg(args, uint64_t), 8, 0);
	else if (c_format->type == 'u')
		ft_print_ouxX(c_format, va_arg(args, uint64_t), 10, 0);
	else if (c_format->type == 'x')
		ft_print_ouxX(c_format, va_arg(args, uint64_t), 16, 0);
	else if (c_format->type == 'X')
		ft_print_ouxX(c_format, va_arg(args, uint64_t), 16, 1);
	
}

int		ft_printf_struct(const char *format, ...)
{
	va_list		args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			format = ft_struct_fill((char *)format, args);
		else
		{
			write(1, format, 1);
			format++;
		}
	}
	va_end(args);
	return (0);
}
