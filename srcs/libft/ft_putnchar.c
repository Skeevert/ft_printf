#include <unistd.h>

void	ft_putnchar(char c, unsigned int n)
{
	while (n-- > 0)
		write(1, &c, 1);
}
