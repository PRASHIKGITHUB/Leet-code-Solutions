#include<bits/stdc++.h>
using namespace std;

int main(){
    string s="prashik";
    stack <char> st;
    for (int i = 0; i < s.length(); i++)
    {
        st.push(s[i]);

    }
    for (int i = 0; i < s.length(); i++)
    {
        s[i]=st.top();
        st.pop();
    }
    cout<<s<<endl;
    return 0;
}