#include <stdio.h>

int	main(void)
{
	int	i = 0;
	int n = 0;

	
	while (i < 7)
	{
		n = 1 << i;
		printf("%i\n", n);
		i++;
	}
	return 0;
}
