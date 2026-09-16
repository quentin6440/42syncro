#include <stdio.h>
#include <ctype.h>

int	add(char **s);

int err = 0;

void	error(char **s)
{
	if (err == 1)
		return ;
	err = 1;
	if (!**s)
		printf("Unexpected end of file\n");
	else
		printf("Unexpected token '%c'\n", **s);
}

int	digit(char **s)
{
	int	res;

	if (isdigit(**s))
		return (*(*s)++ - 48);
	if (**s == '(')
	{
		(*s)++;
		res = add(s);
		if (**s != ')')
			error(s);
		else
			(*s)++;
		return res;
	}
	error(s);
	return 0;
}

int mult(char **s)
{
	int res = digit(s);
	while (**s == '*')
	{
		(*s)++;
		res *= digit(s);
	}
	return res;
}

int add(char **s)
{
	int	res = mult(s);
	while (**s == '+')
	{
		(*s)++;
		res += mult(s);
	}
	return res;
}

int	main(int ac, char *av[])
{
	if (ac != 2)
		return -1;
	char 	*s = av[1];	
	int	res = add(&s);
	if (*s)
		error(&s);
	if (!err)
		printf("%d\n", res);
	return 0;	
}
