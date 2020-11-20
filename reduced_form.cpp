/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduced_forrm.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 01:28:54 by mel-jadi          #+#    #+#             */
/*   Updated: 2020/11/20 06:46:54 by mel-jadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpv1.hpp"

bool    sort_termes(termes a, termes b)
{
    return (a.degree < b.degree);
}

vector <termes> factorise_termes(vector <termes> &t)
{
    vector <termes> res;
    int i = -1;
    double deg;
    termes  r;

    sort(t.begin(), t.end(), sort_termes);
    while (++i < (int)t.size())
    {
        deg = t[i].degree;
        r.coef = 0;
        r.degree = deg;
        while (deg == t[i].degree && i < (int)t.size())
        {
            r.coef = r.coef + t[i].coef;
            i++;
        }
        if (deg != t[i].degree)
            i--;
        res.push_back(r);
    }
    i = -1;
    while (++i < (int)res.size())
    {
        if (res[i].coef == 0)
            res.erase(res.begin() + i);
    }
    if (res.size() == 0)
    {
        r.coef = 0;
        r.degree = 0;
        res.push_back(r);
    }
    return(res);
}

void        reduced_form(vector <termes> t)
{
    int     i;
    int     test;

    i = -1;
    cout << "Reduced form: ";
    while (++i < (int)t.size())
    {
        test = 0;
        if (i != 0)
            cout << " ";
        if (t[i].coef < 0)
        {
            t[i].coef *= -1;
            cout << "- ";
            test = 1;
        }
        else if (i != 0 && t[i].coef > 0)
            cout << "+ ";
        if (t[i].degree > 1 && t[i].coef == 1)
            cout  << "X^" << t[i].degree;
        else if (t[i].degree == 1 && t[i].coef == 1)
            cout  << "X";
        else if (t[i].degree == 0)
            cout << t[i].coef;
        else if (t[i].degree > 1)
            cout << t[i].coef << " * X^" << t[i].degree;
        else if (t[i].degree == 1)
            cout << t[i].coef << " * X";
        if (test)
            t[i].coef *= -1;
    }
    cout << " = 0" << endl;
    cout << "Polynomial degree: " << t[i-1].degree << endl;
    if (t[i-1].degree >= 3)
        error(2);
}
