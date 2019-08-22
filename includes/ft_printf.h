/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boris <boris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:49:45 by boris             #+#    #+#             */
/*   Updated: 2019/08/21 21:28:55 by boris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "main.h"

union						u_doubletoint
{
	double					d;
	unsigned long long int	i;
}							d;

union						u_ldoubletoint
{
	long double				ld;
	int						i[3];
	unsigned long long int	man;
}							ld;

typedef struct				s_long_value
{
	int						*value;
	unsigned long long int	size;
}							t_long_value;

typedef struct				s_karatsuba
{
	t_long_value			*am;
	t_long_value			*as;
	t_long_value			*bm;
	t_long_value			*bs;
}							t_karatsuba;

int							dexp(void);
int							longdexp(void);
void						free_long_value(t_long_value **x);
int							zerotofrc(t_long_value *frc, int prec);
void						normalize(t_long_value *x);
int							sum(t_long_value *a, t_long_value *b);
int							simplecom(t_long_value *a, t_long_value *b);
int							initbinpow(t_long_value **rez,
								t_long_value **pow, int base);
t_long_value				*binpow(int n, int base);
t_long_value				*whole(int n);
int							normrez(t_long_value **x, int pow);
t_long_value				*fraction(int ot, int pow, int status);
char						*wholetostr(t_long_value *wh);
char						*doubletonumber(t_long_value *wh,
								t_long_value *frc, int prec);
int							initlwhole(t_long_value **rez);
t_long_value				*lwhole(int n);
t_long_value				*lfraction(int ot, int pow, int status);
char						*ldoubletostr(int prec);
int							finalprintnahoild(t_format *inf);
int							formfraction(size_t prec, t_long_value *frc);
int							normfraction(t_long_value *frc);
int							normwhole(t_long_value *wh, int plus);
char						*freenumber(t_long_value **wh, t_long_value **frc);
int							normnumber(t_long_value **wh,
									t_long_value **frc, int prec);
char						*doubletostr(int prec);
void						preprint(int zn, t_format *inf);
void						printspase(char c, int i);
void						printnumber(t_format *inf, char *str,
								int zn, int zap);
char						*zerostr(int prec);
int							finalprintnahoid(t_format *inf);
void						lfiksfinal();
void						fiksfinal();

#endif
