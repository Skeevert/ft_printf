/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 12:37:12 by hshawand          #+#    #+#             */
/*   Updated: 2019/04/15 12:05:18 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *destination, const char *source, size_t num)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (destination[i] != '\0')
		i++;
	while (source[j] != '\0' && j < num)
	{
		destination[i] = source[j];
		i++;
		j++;
	}
	destination[i] = '\0';
	return (destination);
}
