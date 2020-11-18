#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct  s_element
{
    double      a;
    double      b;
    double      c;
    char        var;

}               t_element;


char    *create_string(char *s, int debut, int fin)
{
    int     i;
    char    *res;

    i = 0;
    res = (char *)malloc(fin - debut + 2);
    res[fin - debut + 1] = '\0';
    while (i < fin - debut + 1)
    {
        //printf("oui\n");
        res[i] = s[debut];
        debut++;
        i++;
    }
    printf("TEST: %s%%   %d  %d\n", res, debut, fin);
    return(res);
}

char    *check_chars(char *s)
{
    char    *res;
    int     size;
    int     test;
    int     i;
    int     nbr_equal;
    char    var;

    i = -1;
    size = 0;
    nbr_equal = 0;
    var = '0';
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
        if (isalpha(s[i]))
        {
            if (var == '0')
                var = s[i];
            else if (var != s[i])
            {
                printf("equation fausse ou insupportable\n");
                exit(0);
            }
        }
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

void     split_equation(char *s, char **s1, char **s2)
{
    int     i;
    int     j;

    i = 0;
    while (s[i])
    {
        if (s[i] == '=')
            break;
        i++;
    }
    if (i == 0 || i == strlen(s))
    {
        printf("equation fausse ou insupportable\n");
        exit(0);
    }
    *s1 = (char *)malloc(i + 1);
    *s2 = (char *)malloc(strlen(s) - i);
    (*s1)[i] = '\0';
    (*s2)[strlen(s) - i - 1] = '\0';
    j = 0;
    while (j < i)
    {
        (*s1)[j] = s[j];
        j++;
    }
    j++;
    i = 0;
    while (s[j])
    {
        (*s2)[i] = s[j];
        i++;
        j++;
    }
}

void    check_operators(char *s)
{
    int     i;

    i = 0;
    while (s[i])
    {
        if ((s[i] == '+' || s[i] == '-') && (!isalnum(s[i + 1]) || (i != 0 && !isalnum(s[i-1]))))
        {
            printf("equation fausse ou insupportable\n");
            exit(0);
        }

        if ((s[i] == '.') && (!isdigit(s[i + 1]) || i == 0 || !isdigit(s[i-1])))
        {
            printf("equation fausse ou insupportable\n");
            exit(0);
        }
        if ((s[i] == '*') && (!isalnum(s[i + 1]) || i == 0 || !isalnum(s[i-1])))
        {
            printf("equation fausse ou insupportable\n");
            exit(0);
        }
        if ((s[i] == '^') && (!isdigit(s[i + 1]) || i == 0 || !isalpha(s[i-1])))
        {
            printf("equation fausse ou insupportable\n");
            exit(0);
        }
        i++;
    }
    
}

void    put_elements(char *s, t_element e)
{
    int     i;
    int     start;
    int     end;
    int     points;
    double  coef;

    i = 0;
    coef = 1;
    while (s[i])
    {
        if (s[i] == '+' || s[i] == '-')
            i++;
        start = i;
        points = 0;
        while (isdigit(s[i]) || s[i] == '.')
        {
            if (s[i] == '.')
                points++;
            if (points > 1)
            {
                printf("equation fausse ou insupportable\n");
                exit(0);
            }
            i++;
        }
        end = i;
        if (start == end)
        {
            if (!isalpha(s[i]))
            {
                printf("equation fausse ou insupportable\n");
                exit(0);
            }
            else if (s[i + 1] == '^' && (s[i + 3] == '+' || s[i + 3] == '-' || s[i + 3] == '\0'))
            {
                if (s[i + 2] == '0')
                    e.c+= coef;
                else if (s[i + 2] == '1')
                    e.b+= coef;
                else if (s[i + 2] == '2')
                    e.a+= coef;
                else
                {
                    printf("equation fausse ou insupportable\n");
                    exit(0);
                }
            }
            else if (s[i + 1] == '+' || s[i + 1] == '-' || s[i + 1] == '\0')
            {
                e.b++;
            }
            else
            {
                printf("equation fausse ou insupportable\n");
                exit(0);
            }
        }
        else
        {
            if (s[i] == '*')
                i++;
            if (start != 0 && (s[start - 1] == '+' || s[start - 1] == '-'))
                start--;
            coef = atof(create_string(s, start, end));
            if (s[i] == '\0' || s[i] == '+' || s[i] == '-')
            {
                e.c += coef;
                coef = 1;
            }
        }
    }
    
}

int     main(int ac, char **av)
{
    char        *str_eq;
    char        *s1;
    char        *s2;
    t_element   e;
    e.a = 0;
    e.b = 0;
    e.c = 0;

    str_eq = NULL;
    s1 = NULL;
    s2 = NULL;
    //e = (t_element *)malloc(sizeof(struct s_element));

    if (ac != 2)
    {
        printf("usage: kada kada\n");
        return(0);
    }
    str_eq = check_chars(av[1]);
    
    split_equation(str_eq, &s1, &s2);
    check_operators(s1);
    check_operators(s2);
    //printf("%s%%\n%s%%\n%s%%\n", str_eq, s1, s2);
    //put_elements(s1, e);
    printf("a= %f\n", e.a);
    printf("b= %f\n", e.b);
    printf("c= %f\n", e.c);
    return(0);
}