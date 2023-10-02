#include <bits/stdc++.h>
using namespace std;
// note that except ith index everything else is heap
void heapify(int arr[], int size, int i)
{
    int largest = i;
    int leftIndex = 2 * i;
    int rightIndex = 2 * i + 1;

    if (leftIndex <= size && arr[largest] < arr[leftIndex])
    {
        largest = leftIndex;
    }
    if (rightIndex <= size && arr[largest] < arr[rightIndex])
    {
        largest = rightIndex;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, size, largest);
    }
}
void heapSort(int arr[], int size)
{

    int n = size;
    while (n > 1)
    {
        // step 1: swap first element and last element
        swap(arr[1], arr[n]);
        n--;
        // step 2: heapify arr
        heapify(arr, n, 1);
    }
}
int main()
{
    int arr[] = {-1, 1, 2, 3, 4, 5, 8, 7};
    int n = 7;
    //step 1:first build max heap
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
    cout << "before heap sort" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
    //step 2:then heapSort
    heapSort(arr, n);
    cout << "After heap sort" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}