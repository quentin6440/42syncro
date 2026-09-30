#include <stdio.h>

void	print_bits(unsigned char c)
{
	int	i = 7;
	while (i > 0)
	{
		if ((1 << i) & c)
			printf("1");
		else
			printf("0");
		i--;
	}
	printf("\n");
	return ;
}

int main(int ac, char *av[])
{
	int	i = 0;

	if (ac != 2)
		return printf("need one arg");
	while (i < 1)
	{
		print_bits(av[1][i]);
		i++;
	}
	return 0;
}
