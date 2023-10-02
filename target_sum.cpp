#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    vector<vector<int>> ans;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] + arr[j] == s)
            {
                vector<int> v;
                v.push_back(min(arr[i], arr[j]));
                v.push_back(max(arr[i], arr[j]));
                ans.push_back(v);
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

// solution with O(N)
int main()
{

    int i = 0;
    int j = 0;
    vector<int> arr;
    int size=arr.size();
    int counter=0;
    while (i < size - 1 && j < size)
    {
        if (arr[i] + arr[j] == 5)
        {
            cout << "(" << arr[i] << "," << arr[j] << ")";
            cout << endl;
            i++;
            j = i + 1;
            counter++;
        }
        else if (arr[i] + arr[j] != 5)
        {
            j++;
        }
        else if (arr[i] + arr[j] > 5)
        {
            // i++;
            break;
        }
    }

    if (counter == 0)
    {
        cout << endl;
        cout << " No pair exists";
    }
}









#include<bits/stdc++.h>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        int n=nums.size();
        unordered_map<int,int>map;
        for(int i=0;i<n;i++){
            int more=target-nums[i];
            if(map.find(more)!=map.end()){
                return {map[more],i};
            }
            map[nums[i]]=i;
        }
        return {-1,-1};
    }
};