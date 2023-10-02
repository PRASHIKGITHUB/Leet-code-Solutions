#include <bits/stdc++.h>
using namespace std;
int findMinimumCost(string str)
{
    if (str.length() % 2 == 1)
    {
        return -1;
    }

    // Delete valid characters
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        char c = str[i];
        if (c == '{')
        {
            st.push(c);
        }
        else
        {
            if (!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else
            {
                st.push(c);
            }
        }
    }

    // stack contains invalid characters
    int a = 0;
    int b = 0;

    while (!st.empty())
    {
        if (st.top() == '{')
        {
            a++;
        }
        else
        {
            b++;
        }
        st.pop();
    }
    int ans = (a + 1) / 2 + (b + 1) / 2;
    return ans;
}