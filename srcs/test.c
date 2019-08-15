/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 16:11:30 by hshawand          #+#    #+#             */
/*   Updated: 2019/08/15 16:03:05 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>

int		main(void)
{
	int a = 0;

	int out1 = printf("%09d OG_PRINTF\n", a);
	int out2 = ft_printf_struct("%09d MY_PRINTF\n", a);
	printf("%d %d\n", out1, out2);
	return (0);
}
