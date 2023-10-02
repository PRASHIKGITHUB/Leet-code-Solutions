#include <bits/stdc++.h> 
using namespace std;
void heapify(vector<int>&arr, int size, int i)
{
    int smallest = i;
    int leftIndex = 2 * i+1;
    int rightIndex = 2 * i + 2;

    if (leftIndex < size && arr[smallest] > arr[leftIndex])
    {
        smallest = leftIndex;
    }
    if (rightIndex < size && arr[smallest] > arr[rightIndex])
    {
        smallest = rightIndex;
    }

    if (smallest != i)
    {
        swap(arr[smallest], arr[i]);
        heapify(arr, size, smallest);
    }
}
vector<int> buildMinHeap(vector<int> &arr)
{
    int n=arr.size();
   
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
    return arr;
}
