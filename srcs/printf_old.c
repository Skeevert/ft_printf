/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_old.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 11:52:07 by hshawand          #+#    #+#             */
/*   Updated: 2019/06/20 13:42:37 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* diouxX%f */

static void		ft_putuint(unsigned int num)
{
	unsigned int	pow;
	char			digit;

	pow = 1;
	while (num / pow / 10)
		pow *= 10;
	while (pow >= 1)
	{
		digit = num / pow % 10 + '0';
		write(1, &digit, 1);
		pow /= 10;
	}
}

static void		ft_putoct(unsigned int num)
{
	unsigned int	pow;
	char			digit;

	pow = 1;
	while (num / pow / 8)
		pow *= 8;
	while (pow >= 1)
	{
		digit = num / pow % 8 + '0';
		write(1, &digit, 1);
		pow /= 8;
	}
}
static void		ft_puthex(unsigned int num, char mode)
{
	static char		hex1[] = "0123456789abcdef";
	static char		hex2[] = "0123456789ABCDEF";
	unsigned int	pow;

	pow = 1;
	while (num / pow / 16 > 0)
		pow *= 16;
	while (pow >= 1)
	{
		if (mode)
			write(1, hex2 + (num / pow % 16), 1);
		else
			write(1, hex1 + (num / pow % 16), 1);
		pow /= 16;
	}
}

static void		ft_putptr(void *ptr)
{
	uintptr_t		ptr_addr;
	static char		hex[] = "0123456789abcdef";
	uintptr_t		pow;

	ptr_addr = (uintptr_t)ptr;
	write(1, "0x", 2);
	pow = 1;
	while (ptr_addr / pow / 16 > 0)
		pow *= 16;
	while (pow >= 1)
	{
		write(1, hex + (ptr_addr / pow % 16), 1);
		pow /= 16;
	}
}

static char		*ft_spec_catch(char *flag, va_list args)
{
	static char specs[] = "cspdiouxX%f";
	
	flag++;
	if (*flag == specs[0])
		ft_putchar(va_arg(args, int));
	else if (*flag == specs[1])
		ft_putstr(va_arg(args, char *));
	else if (*flag == specs[2])
		ft_putptr(va_arg(args, void *));
	else if (*flag == specs[3] || *flag == specs[4])
		ft_putnbr(va_arg(args, int));
	else if (*flag == specs[5])
		ft_putoct(va_arg(args, int));
	else if (*flag == specs[7])
		ft_puthex(va_arg(args, unsigned int), 0);
	else if (*flag == specs[8])
		ft_puthex(va_arg(args, unsigned int), 1);
	else if (*flag == specs[9])
		write (1, "%", 1);
	flag++;
	return (flag);
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			format = ft_spec_catch((char *)format, args);
		else
		{
			write(1, format, 1);
			format++;
		}
	}
	return (0);
}