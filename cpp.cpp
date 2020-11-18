#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int ac, char **av)
{
    string  s;
    vector <string> tokens; 
    stringstream check1(s); 
    string intermediate;
    if (ac != 2)
    {
        printf("Usage\n");
        exit(0);
    }
    s = av[1];
    if (count(s.begin(), s.end(), '=') != 1)
    {
        printf("error\n");
        exit(0);
    }
    s.erase(remove(s.begin(), s.end(), ' '), s.end()); 
    cout << "remove spaces:  " << s << endl;
     
    while(getline(check1, intermediate, '=')) 
        tokens.push_back(intermediate); 
    for(int i = 0; i < tokens.size(); i++) 
        cout << tokens[i] << '\n';

}

// int main() 
// { 
      
//     string line = "GeeksForGeeks is a must   try"; 
      
//     // Vector of string to save tokens 
//     vector <string> tokens; 
      
//     // stringstream class check1 
//     stringstream check1(line); 
      
//     string intermediate; 
      
//     // Tokenizing w.r.t. space ' ' 
//     while(getline(check1, intermediate, ' ')) 
//     { 
//         tokens.push_back(intermediate); 
//     } 
      
//     // Printing the token vector 
//     for(int i = 0; i < tokens.size(); i++) 
//         cout << tokens[i] << '\n'; 
//     str.erase(remove(str.begin(), str.end(), ' '), str.end()); 
//     return str;
// } 
