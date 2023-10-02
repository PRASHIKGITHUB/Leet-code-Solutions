#include <bits/stdc++.h>
using namespace std;
bool checkrecursion(string &s, int i)
{

    if (i > s.length() - 1 - i)
    {
        return 1;
    }
    if (s[i] != s[s.length() - 1 - i])
    {
        return 0;
    }

    
    return checkrecursion(s, ++i);
}

int main()
{
    string s = "abab";
    cout << checkrecursion(s, 0);

    return 0;
}