/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 13:45:33 by hshawand          #+#    #+#             */
/*   Updated: 2019/08/22 13:13:21 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static char		*ft_flag_catch(char *flag, t_format *c_fmt)
{
	while (*flag)
	{
		if (*flag == ' ')
			c_fmt->flag |= 0x01;
		else if (*flag == '+')
			c_fmt->flag |= 0x02;
		else if (*flag == '-')
			c_fmt->flag |= 0x04;
		else if (*flag == '0')
			c_fmt->flag |= 0x08;
		else if (*flag == '#')
			c_fmt->flag |= 0x10;
		else
			return (flag);
		flag++;
	}
	return (flag);
}

static char		*ft_width_prec_catch(char *flag, t_format *c_fmt)
{
	if ((c_fmt->width = ft_atoi(flag)))
	{
		while (*flag >= '0' && *flag <= '9')
			flag++;
	}
	if (*flag == '.')
	{
		flag++;
		c_fmt->prec_set = 1;
		c_fmt->prec = ft_atoi(flag);
		while (*flag >= '0' && *flag <= '9')
			flag++;
	}
	return (flag);
}

static char		*ft_length_catch(char *flag, t_format *c_fmt)
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
		if (tmp > c_fmt->length)
			c_fmt->length = tmp;
	}
	return (flag);
}

static char		*ft_type_catch(char *flag, t_format *c_fmt)
{
	if (*flag == 'c')
		c_fmt->type = 'c';
	else if (*flag == 's')
		c_fmt->type = 's';
	else if (*flag == 'p')
		c_fmt->type = 'p';
	else if (*flag == 'd')
		c_fmt->type = 'd';
	else if (*flag == 'i')
		c_fmt->type = 'i';
	else if (*flag == 'o')
		c_fmt->type = 'o';
	else if (*flag == 'u')
		c_fmt->type = 'u';
	else if (*flag == 'x')
		c_fmt->type = 'x';
	else if (*flag == 'X')
		c_fmt->type = 'X';
	else if (*flag == 'f')
		c_fmt->type = 'f';
	else if (*flag == '%')
		c_fmt->type = '%';
	c_fmt->type ? (flag++) : 0;
	return (flag);
}

char			*ft_struct_fill(char *flag_start, va_list args)
{
	t_format	c_fmt;
	char		*flag;

	ft_bzero(&c_fmt, sizeof(c_fmt));
	flag = flag_start;
	flag++;
	flag = ft_flag_catch(flag, &c_fmt);
	flag = ft_width_prec_catch(flag, &c_fmt);
	flag = ft_length_catch(flag, &c_fmt);
	flag = ft_type_catch(flag, &c_fmt);
	ft_struct_process(&c_fmt, args);
	return (flag);
}
