#include "main.h"
#include <stdio.h>

int main()
{
	long double a = 1.6;
	int out1 = printf("%Lf OG_PRINTF\n", a);
	int out2 = ft_printf("%Lf MY_PRINTF\n", a);
	printf("%d %d\n", out1, out2);
	return (0);
}
