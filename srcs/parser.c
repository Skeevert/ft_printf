/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 13:45:33 by hshawand          #+#    #+#             */
/*   Updated: 2019/06/27 12:07:10 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static char		*ft_flag_catch(char *flag, t_format *c_format)
{
	while (*flag)
	{
		if (*flag == ' ')
			c_format->flag |= 0x01;
		else if (*flag == '+')
			c_format->flag |= 0x02;
		else if (*flag == '-')
			c_format->flag |= 0x04;
		else if (*flag == '0')
			c_format->flag |= 0x08;
		else if (*flag == '#')
			c_format->flag |= 0x10;
		else
			return (flag);
		flag++;
	}
	return (flag);
}

static char		*ft_width_prec_catch(char *flag, t_format *c_format)
{
	if ((c_format->width = ft_atoi(flag)))
	{
		while (*flag >= '0' && *flag <= '9')
			flag++;
	}
	if (*flag == '.')
	{
		flag++;
		c_format->prec = ft_atoi(flag);
		while (*flag >= '0' && *flag <= '9')
			flag++;
	}
	return (flag);
}

static char		*ft_length_catch(char *flag, t_format *c_format)
{
	int		tmp;

	tmp = 0;
	while (*flag && (*flag == 'h' || *flag == 'l' || *flag == 'L'))
	{
		if (*flag == 'h' && *(flag + 1) == 'h')
			tmp = 1;
		else if (*flag == 'h')
			tmp = 2;
		else if (*flag == 'l' && *(flag + 1) == 'l')
			tmp = 4;
		else if (*flag == 'l')
			tmp = 3;
		else if (*flag == 'L')
			tmp = 5;
		if (tmp == 1 || tmp == 4)
			flag += 2;
		else
			flag++;
		if (tmp > c_format->length)
			c_format->length = tmp;
	}
	return (flag);
}

static char		*ft_type_catch(char *flag, t_format *c_format)
{
	while (!c_format->type && *flag)
	{
		if (*flag == 'c')
			c_format->type = 'c';
		else if (*flag == 's')
			c_format->type = 's';
		else if (*flag == 'p')
			c_format->type = 'p';
		else if (*flag == 'd')
			c_format->type = 'd';
		else if (*flag == 'i')
			c_format->type = 'i';
		else if (*flag == 'o')
			c_format->type = 'o';
		else if (*flag == 'u')
			c_format->type = 'u';
		else if (*flag == 'x')
			c_format->type = 'x';
		else if (*flag == 'X')
			c_format->type = 'X';
		else if (*flag == 'f')
			c_format->type = 'f';
		flag++;
	}
	return (flag);
}

char			*ft_struct_fill(char *flag_start, va_list args)
{
	t_format	c_format;
	char		*flag;

	ft_bzero(&c_format, sizeof(c_format));
	flag = flag_start;
	flag++;
	if (*flag == '%')
	{
		write(1, "%", 1);
		return (flag + 1);
	}
	flag = ft_flag_catch(flag, &c_format);
	flag = ft_width_prec_catch(flag, &c_format);
	flag = ft_length_catch(flag, &c_format);
	flag = ft_type_catch(flag, &c_format);
	ft_struct_process(&c_format, args);
	return (flag);
}
