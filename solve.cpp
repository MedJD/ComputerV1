/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 01:23:13 by mel-jadi          #+#    #+#             */
/*   Updated: 2020/11/20 01:23:17 by mel-jadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpv1.hpp"

double fsqrt(double x)
{
    double res;
    double pas;

    res = 0;
    pas = 1;
    while (pas > 0.000000001)
    {
        if (res * res == x)
            break;
        else if (res * res > x)
        {
            res -= pas;
            pas /= 10;
        }
        res += pas;
    }
    return(res);
}

void    solve_square_equation(vector <termes> t)
{
    double  a = 0;
    double  b = 0;
    double  c = 0;
    int     i = -1;
    double  x1 = 0;
    double  x2 = 0;
    double  d = 0;

    while (++i < (int)t.size())
    {
        if (t[i].degree == 0)
            c = t[i].coef;
        else if (t[i].degree == 1)
            b = t[i].coef;
        else
            a = t[i].coef;
    }
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
                cout << "All real and imaginary numbers are solutions of this equation" << endl;
            else
                cout << "This equation has no solutions" << endl;
        }
        else
        {
            x1 = -c/b;
            if (x1 == 0)
                x1 = 0;
            cout << "This equation has one reel solution: \nX = " << x1 << endl;
        }
    }
    else
    {
        d = b*b - 4*a*c;
        if (d == 0)
        {
            x1 = -(b / (2*a));
            if (x1 == 0)
                x1 = 0;
            cout << "Discriminant is null, then ";
            cout << "this equation has one reel solution: \nX = " << x1 << endl;
        }
        else if (d > 0)
        {
            x1 = (-b +fsqrt(d)) / (2*a);
            x2 = (-b -fsqrt(d)) / (2*a);
            if (x1 == 0)
                x1 = +0;
            if (x2 == 0)
                x2 = +0;
            cout << "Discriminant is strictly positive, then ";
            cout << "this equation has two reel solutions: \nX1 = " << x1 << "\nX2 = " << x2 << endl;
        }
        else
        {
            x1 = -b / (2*a);
            x2 = fsqrt(-d) / (2*a);
            if (x1 == 0)
                x1 = 0;
            if (x2 == 0)
                x2 = 0;
            cout << "Discriminant is strictly negative, then ";
            if ( x1 != 0 && x2 != 1)
                cout << "this equation has two imaginary solutions: \nX1 = " << x1 << " + " << x2 << "i" << "\nX2 = " <<  x1 << " - " << x2 << "i" << endl;
            else if (x1 != 0)
                cout << "this equation has two imaginary solutions: \nX1 = " << x1 << " + " << "i" << "\nX2 = " <<  x1 << " - " << "i" << endl;
            else if (x2 != 1)
                cout << "this equation has two imaginary solutions: \nX1 = "  << x2 << "i" << "\nX2 =" << " -" << x2 << "i" << endl;
            else
                cout << "this equation has two imaginary solutions: \nX1 = "  << "i" << "\nX2 =" << " -" << "i" << endl;
        }
    }
}