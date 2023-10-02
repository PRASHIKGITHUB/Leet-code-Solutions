#include<bits/stdc++.h>
using namespace std;
int power(int a,int b){
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;
    }
    int ans=power(a,b/2);
    if (b&1)
    {
        //odd
        return ans*ans*a;
    }
    else{
        //even
        return ans*ans;
    }
    
}
int main(){
    cout<<power(2,15);

    return 0;
}