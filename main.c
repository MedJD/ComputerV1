#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *delete_spaces(char *s)
{
    char    *res;
    int     size;
    int     test;
    int     i;

    i = -1;
    size = 0;
    while (s[++i])
    {
        test = 0;
        if (s[i] != ' ' && s[i] != '\v' && s[i] != '\t' && (test = 1) == 1)
            size++;
        if (!isalnum(s[i]) && s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '^' && test)
        {
            printf("equation fausse ou insupportable\n");
            exit(0);
        }
    }
    if (!(res = (char *)malloc(size + 1)))
    {
        printf("erreur d'allocation\n");
        exit(0);
    }
    size = 0;
    i = -1;
    while (s[++i])
    {
        if (s[i] != ' ' && s[i] != '\v' && s[i] != '\t' && (res[size] = s[i]) == s[i])
        {
            res[size] = s[i];
            size++;
        }
    }
    res[size] = '\0';
    return(res);
}

int main(int ac, char **av)
{
    char *eq;

    if (ac != 2)
    {
        printf("usage: kada kada\n");
        return(0);
    }
    eq = delete_spaces(av[1]);
    return(0);
}