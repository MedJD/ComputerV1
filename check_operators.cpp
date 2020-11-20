/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operators.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 01:33:06 by mel-jadi          #+#    #+#             */
/*   Updated: 2020/11/20 01:33:09 by mel-jadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpv1.hpp"

string    check_operators(string &s)
{
    int     i;
    int     f;
    string  signes = "";
    char    var = '0';

    f = s.find('=');
    if (f == 0 || f == (int)s.length() - 1)
        error(0);
    if (s[0] != '+' && s[0] != '-')
        s.insert(0, "+");
    f = s.find('=');
    f += 1;
    if (s[f] != '+' && s[f] != '-')
        s.insert(f, "+");
    i = 0;
    while (s[i])
    {
        if ((s[i] == '+' || s[i] == '-') && (!isalnum(s[i + 1]) || (i != 0 && !isalnum(s[i-1]) && s[i-1] != '=')))
            error(0);
        if ((s[i] == '.') && (!isdigit(s[i + 1]) || i == 0 || !isdigit(s[i-1])))
            error(0);
        if ((s[i] == '*') && (!isalnum(s[i + 1]) || i == 0 || !isalnum(s[i-1])))
            error(0);
        if ((s[i] == '^') && (!isdigit(s[i + 1]) || i == 0 || !isalpha(s[i-1])))
            error(0);
        if (s[i] == '+')
        {
            if (i >= f)
                s[i] = '-';
            signes += s[i];
            s[i] = ' ';
        }
        else if(s[i] == '-')
        {
            if (i >= f)
                s[i] = '+';
            signes += s[i];
            s[i] = ' ';
        }
        if (isalpha(s[i]))
        {
            if (var == '0')
                var = s[i];
            else if (var != s[i])
                error(0);
            s[i] = 'X';
        }
        i++;
    }
    return(signes);
}
