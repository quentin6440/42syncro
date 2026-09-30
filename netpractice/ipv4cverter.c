#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int	isBin(int n)
{
	return (n == '0' || n == '1');
}

int	isByte(char *s){
	int	i = 0;

	while (i < 8)
	{
		if (!isBin(s[i]))
			return 0;
//		printf("%i", i);
		i++;
	}
	return s[8] == '\0';
}

int ft_putdec(char *s){
	size_t	i = 0;
	int n = 0;

	while (s && s[i])
	{
		if (s[i] == '1')
// 			n += pow(2, (7 - i));
	n += 1 << (7 - i);
		i++;
	}
	return printf("%i \n", n);
}

int	ft_putbin(int n)
{
	int i = 7;
	char 	a[] = "00000000";
	if (!n || n == 0)
		return printf("%s\n", a);
	while (i >= 0)
	{
		if (n % 2 == 1)
			a[i] = '1';
		i--;
		n /= 2;

	}
	return printf("%s ", a);
}

int	main(int ac, char *av[])
{

	int	n1 = 0;
	int	n2 = 0;
	int	n3 = 0;
	int	n4 = 0;
	if (ac != 5)
	{
		printf("give me an IP baby\n");
		return 1;
	}
	if (isByte(av[1]) && isByte(av[2]) && isByte(av[3]) && isByte(av[4]))
		return ft_putdec(av[1]), ft_putdec(av[2]), ft_putdec(av[3]), ft_putdec(av[4]);
	n1 = atoi(av[1]);
	n2 = atoi(av[2]);
	n3 = atoi(av[3]);
	n4 = atoi(av[4]);
	if (n1 < 0 || n1 > 255 || n2 < 0 || n2 > 255 || n3 < 0 || n3 > 255 || n4 < 0 || n4 > 255)
	{
		printf("Better IP baby, 4 digits 8 bits please, dec or binary only please\n");
		return 1;
	}

	printf("in 8 bits binary : ");
	ft_putbin(n1);
	ft_putbin(n2);
	ft_putbin(n3);
	ft_putbin(n4);
	
	printf("\nin decimal : %i %i %i %i\n", n1, n2, n3, n4);
	return 0;
}
