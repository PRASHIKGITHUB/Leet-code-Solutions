#include<iostream>
using namespace std;
void sort012(int a[], int n)
{
    int low=0;
    int mid=0;
    int high=n-1;
    
    while (mid<=high)
    {
        switch (a[mid])
        {
        case 0:
            swap(a[low++],a[mid++]);
            break;
        
        case 1:
            mid++;
            break;
        
        case 2:
            swap(a[mid],a[high--]);
            break;
        }
    }
    return ;
}
int main(){
    int n;
    cin>>n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int low=0;
    int mid=0;
    int high=n-1;
    
    while (mid<=high)
    {
        switch (arr[mid])
        {
        case 0:
            swap(arr[low++],arr[mid++]);
            break;
        
        case 1:
            mid++;
            break;
        
        case 2:
            swap(arr[mid],arr[high--]);
            break;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    

    return 0;
}