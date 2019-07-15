/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 16:11:30 by hshawand          #+#    #+#             */
/*   Updated: 2019/07/15 14:03:16 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>

int		main(void)
{
	int a = 256;
//	ft_printf("%p, %o, %x, %X\n", &a, a, a, a);
	printf("%030p PRINTF\n", &a);
	ft_printf_struct("%030p MY_PRINTF\n", &a);
	return (0);
}
