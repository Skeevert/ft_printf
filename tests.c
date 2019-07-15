#include "incs/main.h"
#include <stdio.h>

int		main()
{
//	ft_printf("%c%s\n", 'a', "bra");
//	printf("%-20s", "Hello World!");

	int a = 12;
//	ft_printf("%p, %o, %x, %X\n", &a, a, a, a);
	printf("%lu INT_64\n", sizeof(uint64_t));
	printf("%lu PTR_64\n", sizeof(uintptr_t));
	

	return (0);
}
