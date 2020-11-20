/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 01:17:30 by mel-jadi          #+#    #+#             */
/*   Updated: 2020/11/20 01:17:32 by mel-jadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpv1.hpp"

int main(int ac, char **av)
{
    string  s;
    string signes;
    vector <termes> t;
    vector <string> str;
    int i = -1;
    if (ac != 2)
        error(1);
    s = av[1];
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    if (count(s.begin(), s.end(), '=') != 1 || s.length() < 3)
        error(0);
    signes = check_operators(s);
    s.erase(remove(s.begin(), s.end(), '='), s.end());
    t = get_termes(s, signes);
    t = factorise_termes(t);
    reduced_form(t);
    solve_square_equation(t);
}