/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 01:33:52 by mel-jadi          #+#    #+#             */
/*   Updated: 2020/11/20 01:33:53 by mel-jadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpv1.hpp"

void            error(int e)
{
    if (e == 0)
        cout << "Wrong or insupportable equation" << endl;
    else if (e == 1)
        cout << "Usage example: ./computerV1 \" 1 + X^0 + 5 * X^1 = X - X^2 * 5 \"" << endl;
    if (e == 2)
        cout << "The polynomial degree is stricly greater than 2, I can't solve." << endl; 
    exit(0);
}

vector <string> split_string(string s, char c)
{
    stringstream    stmd_s(s);
    vector <string> res;
    string          buff;

    while(getline(stmd_s, buff, c))
    {
        if (buff.length() != 0)
            res.push_back(buff);
    }
    return (res);
}

void            is_int(string s)
{
    int     i = -1;

    while (s[++i])
    {
        if (!isdigit(s[i]))
            error(0);
    }
}

void            is_double(string s)
{
    int     i = -1;
    int     nbr_points = 0;

    while (s[++i])
    {
        if (!isdigit(s[i]) && s[i] != '.')
            error(0);
        if (s[i] == '.')
            nbr_points++;
    }
    if (nbr_points > 1)
        error(0);
}
