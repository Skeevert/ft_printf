/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 12:56:41 by hshawand          #+#    #+#             */
/*   Updated: 2019/04/15 12:13:39 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static size_t	ft_count(const char *str)
{
	size_t		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t		size;
	char		*con;
	size_t		i;

	if (!s1 || !s2)
		return (0);
	size = ft_count(s1) + ft_count(s2) + 1;
	con = (char *)malloc(sizeof(char) * size);
	if (!con)
		return (NULL);
	i = 0;
	while (*s1)
	{
		con[i] = *s1;
		s1 = s1 + 1;
		i++;
	}
	while (*s2)
	{
		con[i] = *s2;
		s2 = s2 + 1;
		i++;
	}
	con[i] = '\0';
	return (con);
}
