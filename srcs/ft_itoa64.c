/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa64.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 15:47:23 by svivienn          #+#    #+#             */
/*   Updated: 2019/07/15 13:59:03 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>

void	ft_itoa64(int64_t c, char *str)
{
    int         size;
    uint64_t    u_save;

    size = 0;
    c < 0 ? (u_save = -c) : (u_save = c);
    if (c < 0)
    {
        size++;
        str[0] = '-';
    }
	while (c != 0 && size++)
		c /= 10;
    str[size] = '\0';
    while (u_save != 0)
    {
        str[size - 1] = (u_save % 10) + '0';
        size--;
        u_save /= 10;
    }
}

void    ft_utoa64(uint64_t c, char *str)
{
    int         size;
    uint64_t    u_save;

    size = 0;
    u_save = c;
    while (c != 10 != 0 && size++)
        c /= 10;
    str[size] = '\0';
    while (u_save != 0)
    {
        str[size - 1] = (u_save % 10) + '0';
        size--;
        u_save /= 10;
    }
}

void	ft_utoa64_base(uint64_t c, char *str, char base, char mode)
{
	int             size;
    uint64_t        u_save;
    static char     mode_0[] = "0123456789abcdef";
    static char     mode_1[] = "0123456789ABCDEF";

    size = 0;
    u_save = c;
    while (c != 0)
    {
        c /= base;
        size++;
    }
    str[size] = '\0';
    while (u_save != 0)
    {
        if (!mode)
            str[size - 1] = mode_0[u_save % base];
        else
            str[size - 1] = mode_1[u_save % base];
        size--;
        u_save /= base;
    }
}