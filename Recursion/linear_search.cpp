#include <bits/stdc++.h>
using namespace std;
void print(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
bool isPresent(int *arr, int key, int size)
{
    print(arr, size);

    if (size == 0)
    {
        return false;
    }
    if (arr[0] == key)
    {
        return true;
    }
    else
    {
        return isPresent(arr + 1, key, size - 1);
    }
}
int main()
{
    int arr[] = {1, 36, 7, 32, 2, 8};
    cout << isPresent(arr, 0, 6) << endl;
    return 0;
}