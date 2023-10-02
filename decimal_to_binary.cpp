#include<bits/stdc++.h>
using namespace std;

int main(){
    // int a=2147483647;
    int a=4;
    
    for (int  i = 31; i>=0; i--)
    {
        if(a>>i!=0){

        cout<<((a>>i)&1);
        }
        
    }
    // negative numbers are repersented in 2's compliment
    
    return 0;
}