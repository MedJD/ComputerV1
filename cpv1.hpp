/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpv1.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 01:17:58 by mel-jadi          #+#    #+#             */
/*   Updated: 2020/11/20 01:18:01 by mel-jadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPV1_HPP
#define CPV1_HPP

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

typedef struct  termes
{
    double  coef;
    int     degree;
}               termes;

int             main(int ac, char **av);
bool            sort_termes(termes a, termes b);
void            reduced_form(vector <termes> t);
void            solve_square_equation(vector <termes> t);
void            is_double(string s);
void            is_int(string s);
void            error(int e);
string          check_operators(string &s);
double          fsqrt(double x);
vector <termes> factorise_termes(vector <termes> &t);
vector <termes> get_termes(string &s, string &signes);
vector <string> split_string(string s, char c);

#endif