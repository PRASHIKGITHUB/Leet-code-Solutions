#include <bits/stdc++.h>
//in place 
string replaceSpaces(string &str)
{
    while (str.back() == ' ')
    {
        str.pop_back();
    }
    str.push_back('#');
    int i = 0;
    while (str[i] != '#')
    {
        if (str[i] == ' ')
        {
            str[i] = '@';
            str.insert(i + 1, "40");
        }
        i++;
    }
    str.pop_back();
    return str;
}