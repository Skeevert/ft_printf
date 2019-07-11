/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 11:02:37 by hshawand          #+#    #+#             */
/*   Updated: 2019/06/19 17:45:20 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h> // TO DELETE

//678324
//313736
//992060

void	ft_putfloat(float value)
{
	unsigned int		exponent;
	unsigned int		mantissa;
	unsigned int		*ptr;
	unsigned int		out = 0;
	unsigned int		testmask = 0x00400000;
	unsigned int		i = 5;

	ptr = (unsigned int *)&value;

	exponent = *ptr & 0x7F800000;
	exponent >>= 23;
	exponent -= 127; 

	mantissa = *ptr & 0x007FFFFF;
	while (testmask)
	{
		if (out > out * 10 + i)
			break ;
		if (testmask & mantissa)
			out = out * 10 + i;
		else
			out *= 10;
		printf("%u\n", out);
		i *= 5;
		testmask >>= 1;
	}
	out /= 10;
	out *= 2;
	printf("EXPONENT: %x\n", exponent);
	printf("MANSTISSA: %x\n", mantissa);
	printf("OUTPUT: %u\n", out);
}

int		main()
{
	ft_putfloat(2.345);
	return (0);
}