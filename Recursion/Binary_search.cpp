#include <bits/stdc++.h>
using namespace std;
void print(int *arr, int s, int end)
{
    for (int i = s; i <= end; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
bool binarySearch(int *arr, int start, int end, int key)
{
    print(arr, start, end);
    int mid = start + (end - start) / 2;
    // element not found
    if (start > end)
    {
        return false;
    }

    // element found
    if (arr[mid] == key)
    {
        return 1;
    }
    else if (key < arr[mid])
    {
        return binarySearch(arr, start, mid - 1, key);
    }
    else
    {
        return binarySearch(arr, mid + 1, end, key);
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    cout << binarySearch(arr, 0, 4, 6) << endl;
    return 0;
}