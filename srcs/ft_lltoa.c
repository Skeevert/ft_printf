/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 15:47:23 by svivienn          #+#    #+#             */
/*   Updated: 2019/07/12 13:29:06 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>

void	ft_itoa64(int64_t c, char *str)
{
    int     size;
    int64_t save;
    
    size = 0;
    save = c;
    while(save != 0)
    {
        size++;
        save = save / 10;
    }
    if (c < 0)
        size++;
    str[size] = '\0';
    if (c < 0)
        str[0] = '-';
    while (c != 0)
    {
        str[size - 1] = (c % 10) + '0';
        size--;
        c = c / 10;
    }
}

/*
char *ft_itoa64(uint64_t c)
{
    int     size;
    uint64_t save;
    char    *str;
    
    size = 0;
    save = c;
    while(save != 0)
    {
        size++;
        save = save / 10;
    }
    str = (char*)malloc(sizeof(char) *  (size + 1));
    str[size] = '\0';
    while (c != 0)
    {
        str[size - 1] = (c % 10) + '0';
        size--;
        c = c / 10;
    }
    return (str);
}
*/