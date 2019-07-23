#include "incs/main.h"
#include <stdio.h>

int		main()
{
//	ft_printf("%c%s\n", 'a', "bra");
//	printf("%-20s", "Hello World!");

	int a = 12;
//	ft_printf("%p, %o, %x, %X\n", &a, a, a, a);
	printf("%#-30.12x\n", a);
	

	return (0);
}
