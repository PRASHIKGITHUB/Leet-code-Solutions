class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.length()!=0 && s.find(part)<s.length()){
            s.erase(s.find(part),part.length());
        }
        return s;
        
    }
};

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    cout<<s.find("abc")<<endl;
    s.erase(s.find("abc"),3);
    cout<<s<<endl;
    return 0;
}