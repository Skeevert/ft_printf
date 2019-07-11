/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 12:42:35 by hshawand          #+#    #+#             */
/*   Updated: 2019/07/08 11:49:51 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H

# define MAIN_H

# include "libft.h"

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h> // uintptr_t
# define STACKSIZE 12000

typedef struct		s_format
{
	char			flag;
	unsigned int	width;
	unsigned int	precision;
	char			length;
	char			type;
}					t_format;

int		ft_printf(const char *format, ...);
int		ft_printf_struct(const char *format, ...);
char	*ft_struct_fill(char *flag_start, va_list args);
void	ft_struct_process(t_format *c_format, va_list args);

void	ft_print_s(t_format *c_format, char *str);
void	ft_print_c(t_format *c_format, char c);
void	ft_print_p(t_format *c_format, void *ptr);

#endif