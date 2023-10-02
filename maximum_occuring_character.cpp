#include <bits/stdc++.h>
using namespace std;
char temp(string s)
{
    int count[26] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        int chindex=0 ;
        char ch=s[i];
        if (ch <= 'z' && ch >= 'a')
        {
            chindex = ch - 'a';
        }
        else
        {
            chindex = ch - 'A';
        }
        count[chindex]++;
    }
    for (int i = 0; i < 26; i++)
    {
        cout<<count[i]<<" ";
    }
    
    int ans=0;
    int max = -1;
    for (int i = 0; i < 26; i++)
    {
        if (count[i] > max)
        {
            ans = i;
            max = count[i];
        }
    }
    cout<<endl;
    char final='a'+ans;
    
    return final;
}
int main()
{
    string s;
    cin >> s;
    cout <<temp(s) << endl;
    
    return 0;
}