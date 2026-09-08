#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

static char *g;
static int err;

static void parse_expr(void);

static void fail(void)
{
	if (err) return;
	err = 1;
	if (*g == '\0')
		printf("Unexpected end of input\n");
	else
		printf("Unexpected token '%c'\n", *g);
}

static int parse_factor(void)
{
	int v;

	if (isdigit((unsigned char)*g))
		return (*g++ - '0');
	if (*g == '(')
	{
		g++;
		parse_expr();
		v = 0; /* valeur déjà laissée par parse_expr via retour indirect ? non */
		/* On a besoin d'une vraie version avec retour int -> voir ci-dessous */
	}
	fail();
	return 0;
}

/* --- Version correcte avec retours int --- */

static int expr(void);

static int factor(void)
{
	int v;

	if (isdigit((unsigned char)*g))
		return (*g++ - '0');
	if (*g == '(')
	{
		g++;
		v = expr();
		if (*g == ')')
			g++;
		else
			fail();
		return v;
	}
	fail();
	return 0;
}

static int term(void)
{
	int v = factor();
	while (!err && *g == '*')
	{
		g++;
		v *= factor();
	}
	return v;
}

static int expr(void)
{
	int v = term();
	while (!err && *g == '+')
	{
		g++;
		v += term();
	}
	return v;
}

int main(int ac, char **av)
{
	int r;

	if (ac != 2)
		return 1;
	g = av[1];
	err = 0;
	r = expr();
	if (!err && *g != '\0')
		fail();
	if (err)
		return 1;
	printf("%d\n", r);
	return 0;
}
