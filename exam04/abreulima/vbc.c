#include <stdio.h>
#include <ctype.h>

char *c;
int err = 0;

int add();

void error()
{
    if (err == 1)
        return ;
    err = 1;
    if (*c == '\0')
        printf("Unx end\n");
    else
        printf("Unx toekn %c\n", *c);
}

int digit()
{
    int res = 0;
    if (isdigit(*c))
        return (*c++ - '0');

    if (*c == '(')
    {
        c++;

        res = add();

        if (*c != ')')
            error();
        
        c++;
        return (res);
    }
    error();
    return res;
}

int mult()
{
    int res = digit();
    while (*c == '*')
    {
        c++;
        res *= digit();
    }
    return res;
}

int add()
{
    int res = mult();
    while (*c == '+')
    {
        c++;
        res += mult();
    }
    return res;
}


// +
// *
// ()
// digit

int main(int argc, char *argv[])
{

    if (argc != 2)
        return 0;

    c = argv[1];
    
    int res = add();

    if (*c != '\0')
        error();

    if (err == 0)
        printf("%d\n", res);

    return 0;

}
