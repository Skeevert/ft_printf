/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 12:42:35 by hshawand          #+#    #+#             */
/*   Updated: 2019/08/22 14:49:55 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H

# define MAIN_H

# include "libft.h"

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

typedef struct	s_format
{
	char		flag;
	size_t		width;
	size_t		prec;
	char		prec_set;
	char		sign;
	char		length;
	char		type;
}				t_format;

size_t			g_output_size;

int				ft_printf(const char *format, ...);
void			gwrite(int stream, const char *str, size_t size);
void			ft_putnchar(char c, unsigned int n);
char			*ft_struct_fill(char *flag_start, va_list args);
void			ft_struct_process(t_format *c_format, va_list args);
void			ft_itoa64(int64_t d, char *str, t_format *c_fmt);
void			ft_utoa64(uint64_t c, char *str);
void			ft_utoa64_base(uint64_t c, char *str, char base, char mode);

void			ft_print_s(t_format *c_format, char *str);
void			ft_print_c(t_format *c_format, char c);
void			ft_print_p(t_format *c_format, void *ptr);
void			ft_print_d(t_format *c_format, int64_t d);
void			ft_print_ouxx(t_format *c_format, uint64_t d, char base,
		char mode);
void			ft_print_f(t_format *c_fmt, va_list args);
void			ft_zero_zero(t_format *c_fmt, char *str, char base);

#endif
