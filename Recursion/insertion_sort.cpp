#include <bits/stdc++.h>
using namespace std;
void insetionSort(vector<int> &arr, int i)
{
    if (i > arr.size()-1)
    {
        return;
    }
    int j = i - 1;
    int current = arr[i];
    for (; j >= 0; j--)
    {
        if (arr[j] > current)
        {
            arr[j + 1] = arr[j];
        }
        else
        {
            break;
        }
    }
    arr[j + 1] = current;
    insetionSort(arr, i + 1);
}
int main()
{
    vector<int> v={5,4,3,2,1};
    insetionSort(v,1);
    for(int i=0;i<5;i++){
        cout<<v[i]<<" ";
    }

    return 0;
}