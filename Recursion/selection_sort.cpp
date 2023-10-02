#include <bits/stdc++.h>
using namespace std;
void selectionSort(int *arr, int size)
{
    if (size == 1)
    {
        return;
    }
    
    int minindex = 0;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < arr[minindex])
        {
            minindex = i;
        }
    }
    swap(arr[0], arr[minindex]);
    selectionSort(arr + 1, size - 1);
}
int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    selectionSort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}