#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	helpa;

	helpa = n;
	if (helpa < 0)
	{
		ft_putchar_fd('-', fd);
		helpa *= -1;
	}
	if (helpa >= 10)
	{
		ft_putnbr_fd(helpa / 10, fd);
		ft_putchar_fd(helpa % 10 + '0', fd);
	}
	else
		ft_putchar_fd(helpa + '0', fd);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
