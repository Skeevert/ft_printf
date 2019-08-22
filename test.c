#include "main.h"
#include <stdio.h>

int main()
{
	int a = 0;
	int out1 = printf("%#.o OG_PRINTF\n", a);
	int out2 = ft_printf("%#.o MY_PRINTF\n", a);
	printf("%d %d\n", out1, out2);
	return (0);
}
