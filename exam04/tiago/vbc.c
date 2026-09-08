# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>

int nbr(char *s, int *i);
int sum(char *s, int *i);
int product(char *s, int *i);

int parse(char *s)
{
    int open = 0;

    if (s[0] == '+' || s[0] == '*' || s[0] == ')')
        return (printf("Unexpected token '%c'\n", s[0]), 0);
    for (int i = 0; s[i]; i++)
    {
        if (isdigit(s[i]) && (isdigit(s[i + 1]) || s[i + 1] == '('))
            return (printf("Unexpected token '%c'\n", s[i + 1]), 0);
        if (s[i] == '+' || s[i] == '*')
        {
            if (s[i + 1] == '+' || s[i + 1] == '*' || s[i + 1] == ')' )
                return (printf("Unexpected token '%c'\n", s[i + 1]), 0);
            if (!s[i + 1])
                return (printf("Unexpected end of input\n"), 0);
        }
        if (s[i] == '(')
        {
            open++;
            if (s[i + 1] == ')' || s[i + 1] == '+' || s[i + 1] == '*')
                return (printf("Unexpected token '%c'\n", s[i + 1]), 0);
            if (!s[i + 1])
                return (printf("Unexpected end of input\n"), 0);
        }
        if (s[i] == ')')
        {
            open--;
            if (open < 0)
                return (printf("Unexpected token '%c'\n", s[i]), 0);
            if (isdigit(s[i + 1]) || s[i + 1] == '(')
                return (printf("Unexpected token '%c'\n", s[i + 1]), 0);
        }
        if (!isdigit(s[i]) && s[i] != '+' && s[i] != '*' && s[i] != '(' && s[i] != ')')
            return (printf("Unexpected token '%c'\n", s[i]), 0);
    }
    if (open > 0)
        return (printf("Unexpected end of input\n"), 0);
    return 1;
}
/*
MORE ROBUST
int nbr(char *s, int *i)
{
    int a = 0;

    if (isdigit((unsigned char)s[*i]))
    {
        while (isdigit((unsigned char)s[*i])) // multi-digit
        {
            a = a * 10 + (s[*i] - '0');
            (*i)++;
        }
        return a;
    }
    if (s[*i] == '(')
    {
        (*i)++;              // skip '('
        a = sum(s, i);
        if (s[*i] == ')')
            (*i)++;          // skip ')'
        return a;
    }
    return 0;
}
*/
int nbr(char *s, int *i)
{
    int a = 0;
    if (isdigit(s[*i]))
    {
        a = s[*i] - '0';
        (*i)++;
        return a;
    }
    while (s[*i] == '(')
    {
        (*i)++;
        a = sum(s, i);
        (*i)++;
    }
    return a;
}

int product(char *s, int *i)
{
    int a = nbr(s, i);
    while (s[*i] == '*')
    {
        (*i)++;
        a *= nbr(s, i);
    }
    return a;
}

int sum(char *s, int *i)
{
    int a = product(s, i);
    while (s[*i] == '+')
    {
        (*i)++;
        a += product(s, i);
    }
    return a;
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);
    if (!parse(argv[1]))
        return 1;
    int i = 0;
    printf("%d\n", sum(argv[1], &i));
}
