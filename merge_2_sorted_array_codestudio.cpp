#include <bits/stdc++.h>
using namespace std;
void ninjaAndSortedArrays(vector<int> &arr1, vector<int> &arr2, int m, int n)
{
	int i = 0;
	int j = 0;
	while (i < m)
	{
		if (arr1[i] < arr2[j])
		{
			i++;
		}
		else
		{
			swap(arr1[i], arr2[j]);
			i++;
		}
	}

	while (i < m+n)
	{
		arr1[i++] = arr2[j++];
	}
}
int main()
{
	vector<int> arr1 = {3, 6, 9, 0, 0};
	vector<int> arr2 = {4, 10};
	ninjaAndSortedArrays(arr1, arr2, 3, 2);
	for (int i = 0; i < 5; i++)
	{
		cout << arr1[i] << " ";
	}

	return 0;
}