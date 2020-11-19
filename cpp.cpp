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


void    error(int e)
{
    if (e == 0)
        cout << "equation fausse ou insupportable" << endl;
    else if (e == 1)
        cout << "Usage" << endl;
    exit(0);
}

string    check_operators(string &s)
{
    int     i;
    int     f;
    string  signes = "";
    char    var = '0';

    f = s.find('=');
    if (f == 0 || f == s.length() - 1)
        error(0);
    if (s[0] != '+' && s[0] != '-')
        s.insert(0, "+");
    f += 2;
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

void    check_terme(string &s)
{
    int i;
}

vector <string>     split_string(string s, char c)
{
    stringstream    stmd_s(s);
    vector <string> res;
    string          buff;

    while(getline(stmd_s, buff, c))
        res.push_back(buff);
    return (res);
}

void               is_int(string s)
{
    int     i = -1;

    while (s[++i])
    {
        if (!isdigit(s[i]))
            error(0);
    }
}

void               is_double(string s)
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
    while (++i < terme.size())
    {
        if (count(terme[i].begin(), terme[i].end(), '*') == 1)
        {
            spl_terme.clear();
            spl_terme = split_string(terme[i], '*');
            j = -1;
            while (++j < spl_terme.size())
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
    //coef = t[0];
    while (++i < t.size())
    {
        deg = t[i].degree;
        r.coef = 0;
        r.degree = deg;
        while (deg == t[i].degree && i < t.size())
        {
            r.coef = r.coef + t[i].coef;
            i++;
        }
        if (deg != t[i].degree)
            i--;
        res.push_back(r);
    }
    return(res);
}

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
    //cout << "remove spaces:  " << s << endl;
    signes = check_operators(s);
    //cout << "signes: " << signes << endl;
    s.erase(remove(s.begin(), s.end(), '='), s.end());
    //cout << "to split:" << s << "%" << endl;
    s = s.substr(1);
    //s.erase(remove(s.begin(), s.end(), ' '), s.end());
    str = split_string(s, ' ');
    t = get_termes(s, signes);
    t = factorise_termes(t);
    while (++i < t.size())
        cout << "coef:" << t[i].coef << " deg: " << t[i].degree << endl;
}
