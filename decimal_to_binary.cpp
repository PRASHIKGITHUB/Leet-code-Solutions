#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
void msb(lli x)
{
    if (x == 0)
    {
        cout << "0" << endl;
        return;
    }
    int cnt = 0;
    while (1)
    {
        if (x != 0)
        {
            cnt++;
            x = x >> 1;
        }
        else
        {
            cout << cnt << endl;
        }
    }
}
void print(lli x)
{
    for (lli i = 60; i >= 0; i--)
    {
        cout << ((x >> i) & (1LL));
    }
    cout << endl;
}

int main()
{
    // lli x = -1;
    // print(x);

    // print(x - 1);
    // print(x - 2);
    // print(x - 3);
    // print(x - 4);
    // cout << x << endl;
    for (int i = 0; i <= (1LL << 3) - 1; i++)
    {
        cout<<"hello"<<endl;
    }
    return 0;
}