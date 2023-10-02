#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &A, int B)
{
    int sumA = 0;
    for (int i = 0; i < A.size(); i++)
    {
        sumA += A[i];
    }
    int i = 0;
    int j = A.size() - B - 1;

    int minA = 0;
    for (int k = i; k <= j; k++)
    {
        minA += A[k];
    }

    i++;
    j++;
    int temp=minA;
    while (j<A.size())
    {
        temp+=A[j]-A[i-1];
        minA=min(temp,minA);
        i++;j++;
    }
    
    return sumA - minA;
}

int main()
{
    vector<int> v = {7, -2, 100, 1, 2};
    cout << solve(v, 3);
    return 0;
}
