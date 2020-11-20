/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_terms.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 01:31:37 by mel-jadi          #+#    #+#             */
/*   Updated: 2020/11/20 01:31:41 by mel-jadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpv1.hpp"

vector <termes>    get_termes(string &s, string &signes)
{
    vector <string> terme;
    vector <termes> t;
    vector <string> spl_terme;
    int             i = -1;
    int             j = -1;
    int             f;
    string          str_aux;
    termes          aux;

    terme = split_string(s, ' ');
    while (++i < (int)terme.size())
    {
        if (count(terme[i].begin(), terme[i].end(), '*') == 1)
        {
            spl_terme.clear();
            spl_terme = split_string(terme[i], '*');
            j = -1;
            while (++j < (int)spl_terme.size())
            {
                if (count(spl_terme[j].begin(), spl_terme[j].end(), 'X') > 1)
                    error(0);
                if (count(spl_terme[j].begin(), spl_terme[j].end(), 'X') == 1)
                {
                    if ((f = spl_terme[j].find('^')) < 0)
                        aux.degree = 1;
                    else
                    {
                        spl_terme[j].erase(remove(spl_terme[j].begin(), spl_terme[j].end(), '^'));
                        spl_terme[j].erase(remove(spl_terme[j].begin(), spl_terme[j].end(), 'X'));
                        is_int(spl_terme[j]);
                        aux.degree = stoi(spl_terme[j]);
                    }
                }
                else if (count(spl_terme[j].begin(), spl_terme[j].end(), 'X') == 0)
                {
                    is_double(spl_terme[j]);
                    aux.coef = stod(spl_terme[j]);
                }
                else
                    error(0);
            }
        }
        else if (count(terme[i].begin(), terme[i].end(), '*') == 0)
        {
            if (count(terme[i].begin(), terme[i].end(), 'X') == 0)
            {
                is_double(terme[i]);
                aux.coef = stod(terme[i]);
                aux.degree = 0;
            }
            else if (count(terme[i].begin(), terme[i].end(), 'X') == 1)
            {
                spl_terme.clear();
                spl_terme = split_string(terme[i], 'X');
                if (spl_terme.size() == 0)
                {
                    aux.coef = 1;
                    aux.degree = 1;
                }
                else if (spl_terme.size() == 1)
                {
                    if (count(spl_terme[0].begin(), spl_terme[0].end(), '^') == 1)
                    {
                        spl_terme[0].erase(remove(spl_terme[0].begin(), spl_terme[0].end(), '^'));
                        is_int(spl_terme[0]);
                        aux.degree = stoi(spl_terme[0]);
                        aux.coef = 1;
                    }
                    else if (count(spl_terme[0].begin(), spl_terme[0].end(), '^') == 0)
                    {
                        aux.degree = 1;
                        is_double(spl_terme[0]);
                        aux.coef = stod(spl_terme[0]);
                    }
                    else
                        error(0);
                }
                else if (spl_terme.size() == 2)
                {
                    j = -1;
                    while (++j < 2)
                    {
                        if (count(spl_terme[j].begin(), spl_terme[j].end(), '^') == 1)
                        {
                            spl_terme[j] = spl_terme[j].substr(1);
                            is_int(spl_terme[j]);
                            aux.degree = stoi(spl_terme[j]);
                        }
                        else if (count(spl_terme[j].begin(), spl_terme[j].end(), '^') == 0)
                        {
                            is_double(spl_terme[j]);
                            aux.coef = stod(spl_terme[j]);
                        }
                        else
                            error(0);
                    }
                }
            }
            else
                error(0);
        }
        else
            error(0);
        if (signes[i] == '-')
            aux.coef *= -1;
        t.push_back(aux);
    }
    return(t);
}
