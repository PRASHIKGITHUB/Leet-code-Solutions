#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    if (a==0)   
    {
        return b;
    }
    else{
        return a;
    }
    if (a>b)
    {
        int temp=a;
        a=b;
        b=a;
    }
    return gcd(b%a,a);
    
    
}
int main()
{
    cout<<gcd(24,72)<<endl;
    return 0;
}