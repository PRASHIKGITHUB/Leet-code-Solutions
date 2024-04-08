#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
void print(lli x)
{
    for (lli i = 63; i >= 0; i--)
    {
        cout << ((x >> i) & (1LL));
    }
    cout << endl;
}
void msb(lli x)
{
    if (x == 0)
    {
        cout << "-1" << endl;
        return;
    }
    else if (x < 0)
    {
        cout << "63" << endl;
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
            cout << cnt - 1 << endl;
            return;
        }
    }
}
void rmb(lli x)
{
    if (x == 0)
    {
        cout << "-1" << endl;
        return;
    }
    for (int i = 0; i < 64; i++)
    {
        if ((x >> i) & 1LL)
        {
            cout << i << endl;
            return;
        }
    }
}
void is_power(lli x)
{
    if (x > 1)
    {
        if ((x & (x - 1)) == 0)
        {
            cout << "1" << endl;
        }
        else
        {
            cout << "0" << endl;
        }
    }
    else
    {
        cout << "0" << endl;
    }
}
void biggest_power(lli x)
{
    if(x==0){
        cout<<"-1"<<endl;
        return;
    }
    if (x % 2 == 0)
    {
        for (int i = 0; i < 64; i++)
        {
            if ((x >> i) & 1LL)
            {
                cout << i << endl;
                return;
            }
        }
    }
    else{
        cout<<"-1"<<endl;
    }
}
void solve()
{
    lli x;
    cin >> x;
    print(x);
    msb(x);
    rmb(x);
    is_power(x);
    biggest_power(x);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}