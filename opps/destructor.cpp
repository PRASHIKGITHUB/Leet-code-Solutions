#include <bits/stdc++.h>
using namespace std;
class hello
{
public:
    int a;
    // ~hello(){
    //     cout<<"Destructor is called"<<endl;
    // }
};
int main()
{
    hello h1;// for static objects it is called by default
    hello* h2=new hello; // for dynamic objects we manually have to call them
    delete h2;

    return 0;
}