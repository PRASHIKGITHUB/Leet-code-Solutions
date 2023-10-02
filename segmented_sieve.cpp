#include <bits/stdc++.h>
using namespace std;
int N = 1000000;
vector<bool> seive(N + 1, true);
void createSeive()
{
    for (int i = 2; i * i <= N; i++)
    {
        if (seive[i] == true)
        {
            for (int j = 2 * i; j <= N; j = j + i)
            {
                seive[j] = false;
            }
        }
    }
}

vector<int> GeneratePrimes(int N){
    vector<int> ds;
    for (int i = 2; i <= N; i++)
    {
        if (seive[i]==true)
        {
            ds.push_back(seive[i]);
        }
        
    }
    return ds;
    
}
int main()
{
    createSeive();
    int l,r;
    cin>>l >>r;
    //step 1 :  generate all primes till sqrt(r)
    vector<int> primes=GeneratePrimes(sqrt(r));

    //step 2: 
    //create a dummy vector of size r-1+1 and make everyone true
    vector<bool> dummy(r-1+1,1);
    return 0;
}