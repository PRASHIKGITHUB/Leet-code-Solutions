#include <bits/stdc++.h>
using namespace std;
void reverse(char* s, int i, int j)
{
    if (i > j)
    {
        return;
    }
    swap(s[i++], s[j--]);
    reverse(s, i, j);
}
int main()

{
    string s="abcde";
    char* a=&s[0];
    reverse(a,0,s.length()-1);
    cout<<s<<endl;
    return 0;
}