/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 12:42:35 by hshawand          #+#    #+#             */
/*   Updated: 2019/07/12 15:58:35 by hshawand         ###   ########.fr       */
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
	unsigned int	prec;
	char			length;
	char			type;
}					t_format;

int		ft_printf(const char *format, ...);
int		ft_printf_struct(const char *format, ...);
char	*ft_struct_fill(char *flag_start, va_list args);
void	ft_struct_process(t_format *c_format, va_list args);
void	ft_itoa64(int64_t d, char *str);
void    ft_utoa64(uint64_t c, char *str);
void	ft_utoa64_base(uint64_t c, char *str, char base, char mode);

void	ft_print_s(t_format *c_format, char *str);
void	ft_print_c(t_format *c_format, char c);
void	ft_print_p(t_format *c_format, void *ptr);
void	ft_print_d(t_format *c_format, int64_t d);
void	ft_print_oxX(t_format *c_format, uint64_t d, char base, char mode);

#endif
