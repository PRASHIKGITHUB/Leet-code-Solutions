#include <iostream>
using namespace std;
int main()
{
    int arr[] = {0,1,0,1,0};
    int i = 0;
    int j = 4;
    while (i < j)
    {
        if (arr[i] == 0 )
        {
            i++;
        }
        if (arr[j] == 1)
        {
            j--;
        }
        if (arr[i] == 1 && arr[j] == 0 && i<j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }

        // for (int m = 0; m < 5; m++)
        // {
        //     cout << arr[m] << " ";
        // }
        //     cout << endl;
    }
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
        
    }

    return 0;
}