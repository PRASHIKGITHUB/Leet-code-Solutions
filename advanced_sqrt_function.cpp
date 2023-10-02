#include <iostream>
using namespace std;
long long int binarySearch(int x)
{
    int s = 0;
    int e = x;
    long long int ans = -1;
    long long int mid = s + (e - s) / 2;
    while (s <= e)
    {
        long long int square = mid * mid;

        if (square == x)
        {
            return mid;
        }
        if (square < x)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
int mySqrt(int x)
{
    return binarySearch(x);
}

double morePresion(int n, int presion, int tempsol)
{
    float flag = 1;
    double ans = tempsol;
    for (int i = 0; i < presion; i++)
    {
        flag = flag / 10;
        for (double j = ans; j * j < n; j = j + flag)
        {
            ans = j;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    int tempsol = binarySearch(n);
    cout << morePresion(n, 3, tempsol);
    return 0;
}