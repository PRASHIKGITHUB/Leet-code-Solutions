#include <bits/stdc++.h>
using namespace std;
// T.C->O(n)
// S.C->O(n)+O(n)
int solve(int n, int arr[])
{
    if (n <= 1)
    {
        return n;
    }
    if (arr[n] != -1)
    {
        return arr[n];
    }
    else
    {
        arr[n] = solve(n - 1, arr) + solve(n - 2, arr);
        return arr[n];
    }
}
int main()
{
    int N;
    cin >> N;
    int arr[N + 1];
    for (int i = 0; i <= N; i++)
    {
        arr[i] = -1;
    }
    cout << solve(N, arr);
    return 0;
}
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// tc is greater than previous solution
// sc is same
#include <bits/stdc++.h>
using namespace std;
int solve(int n, int arr[])
{
    if (n <= 1)
    {
        return n;
    }
    if (arr[n] != -1)
    {
        return arr[n];
    }
    else
    {
        arr[n] = solve(n - 1, arr) + solve(n - 2, arr);
        return arr[n];
    }
}
int main()
{
    int N;
    cin >> N;
    int arr[N + 1];
    for (int i = 0; i <= N; i++)
    {
        arr[i] = -1;
    }
    cout << solve(N, arr);
    return 0;
}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$444
// T.C->O(n)
// S.C->O(n)
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n + 1];
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    cout << arr[n];
    return 0;
}

//**************************************************************************
// T.C->O(n)
// S.C->O(1)
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n <= 1)
    {
        cout << n;
        return 0;
    }
    int pp = 0;
    int p = 1;
    int temp = 0;
    for (int i = 2; i <= n; i++)
    {
        temp = p + pp;
        pp = p;
        p = temp;
    }
    cout << temp;
    return 0;
}