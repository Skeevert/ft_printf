/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:42:41 by hshawand          #+#    #+#             */
/*   Updated: 2019/08/20 13:29:10 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>

void	ft_putnchar(char c, unsigned int n)
{
	g_output_size += n;
	while (n-- > 0)
		write(1, &c, 1);
}

void	gwrite(int stream, const char *str, size_t size)
{
	g_output_size += write(stream, str, size);
}

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
		ft_print_ouxx(c_format, va_arg(args, uint64_t), 8, 0);
	else if (c_format->type == 'u')
		ft_print_ouxx(c_format, va_arg(args, uint64_t), 10, 0);
	else if (c_format->type == 'x')
		ft_print_ouxx(c_format, va_arg(args, uint64_t), 16, 0);
	else if (c_format->type == 'X')
		ft_print_ouxx(c_format, va_arg(args, uint64_t), 16, 1);
	else if (c_format->type == 'f')
		ft_print_f(c_format, args);
}

int		ft_printf(const char *format, ...)
{
	va_list		args;

	va_start(args, format);
	g_output_size = 0;
	while (*format)
	{
		if (*format == '%')
			format = ft_struct_fill((char *)format, args);
		else
		{
			gwrite(1, format, 1);
			format++;
		}
	}
	va_end(args);
	return (g_output_size);
}
