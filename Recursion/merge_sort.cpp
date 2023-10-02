#include <bits/stdc++.h>
using namespace std;
void mergeTwoSortedArray(int *arr, int s, int e)
{
    int mid = s + (e - s) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    // copy values
    int mainIndex = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainIndex++];
    }

    mainIndex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainIndex++];
    }

    // merge 2 sorted array
    int index1 = 0;
    int index2 = 0;
    mainIndex = s;
    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainIndex++] = first[index1++];
        }
        else
        {
            arr[mainIndex++] = second[index2++];
        }
    }

    while (index1 < len1)
    {
        arr[mainIndex++] = first[index1++];
    }
    while (index2 < len2)
    {
        arr[mainIndex++] = second[index2++];
    }
    delete []first;
    delete []second;
}
void mergeSort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }

    int mid = s + (e - s) / 2;
    // left part sort karna hai
    mergeSort(arr, s, mid);
    // right part sort karna hai
    mergeSort(arr, mid + 1, e);

    mergeTwoSortedArray(arr, s, e);
}
int main()
{
    int arr[]={2,21,0,1,5,2,8,12,90,8,8,3};
    mergeSort(arr,0,11);
    for (int i = 0; i < 12; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}