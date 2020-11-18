#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct  s_eq
{
    float   a;
    float   b;
    float   c;
    char    var;
}               t_eq;

char    *delete_spaces(char *s)
{
    char    *res;
    int     size;
    int     test;
    int     i;
    int     nbr_equal;

    i = -1;
    size = 0;
    nbr_equal = 0;
    while (s[++i])
    {
        test = 0;
        if (s[i] != ' ' && s[i] != '\v' && s[i] != '\t' && (test = 1) == 1)
            size++;
        if (!isalnum(s[i]) && s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '^' && s[i] != '=' && s[i] != '.' && test)
        {
            printf("equation fausse ou insupportable\n");
            exit(0);
        }
        if(s[i] == '=')
            nbr_equal++;
    }
    if (nbr_equal != 1)
    {
        printf("equation fausse ou insupportable\n");
        exit(0);
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

int     check_form(char *s)
{
    int     i;

    i = -1;
    if (strlen(s) < 3)
    {
        printf("equation fausse ou insupportable\n");
        exit(0);
    }
    while (s[++i])
    {
        if (isdigit(s[i]) && !isdigit(s[i + 1]) && s[i + 1] != '.' && s[i + 1] != '*' && s[i + 1] != '*' && s[i + 1] != '*' && s[i + 1] != '*')

    }
    
}

double  str_to_double(char *s, int debut, int fin)
{
    char *n;
    int     i;
    double  res;

    n = malloc(fin - debut + 1);
    n[fin - 1] = '\0';
    i = -1;
    while (n[++i])
    {
        n[i] = s[debut];
        debut++;
    }
    res = atof(n);
    free(n);
    return(res);
}

int     str_to_eq(char *s, t_eq *eq)
{
    int     i;
    int     debut;
    int     fin;
    int     nbr_points;
    double  aux;
    
    i = -1;
    
    while (s[++i])
    {
        debut = i;
        nbr_points = 0;
        while (s[i]isdigit(s[i]) || s[i] == '.')
        {
            if (s[i] == '.')
            {
                nbr_points++;
                if (nbr_points > 1 || !isdigit(s[i+1]))
                {
                    printf("equation fausse ou insupportable\n");
                    exit(0);
                }
            }
            i++;
        }
        fin = i;
        if (debut != fin)
        {
            aux = str_to_double(s, debut, fin);
            if (debut != 0 && s[debut - 1] == '-')
                aux *= -1;
            if (s[i] == '+' || s[i] == '-' || s[i] == '=' || s[i] == '\0')
                eq->c += aux;
            if (isalpha(s[i]) || s[i] == '*')
            {
                if (s[i] == '*' && s[i + 1] &)
                    i++;
                if (eq->var == '0')
                    eq->var = s[i]
            }
        }
    
    }
    

}

int     main(int ac, char **av)
{
    char    *str_eq;
    t_eq    eq;

    if (ac != 2)
    {
        printf("usage: kada kada\n");
        return(0);
    }
    str_eq = delete_spaces(av[1]);
    eq.a = 0;
    eq.b = 0;
    eq.c = 0;
    eq.var = '0';
    printf("%s\n", str_eq);
    return(0);
}