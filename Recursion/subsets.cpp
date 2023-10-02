#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void solve(vector<int> &nums, int index, vector<int> result, vector<vector<int>> &ans)
    {
        if (index >= nums.size())
        {
            ans.push_back(result);
            return;
        }

        // exclude
        solve(nums, index + 1, result, ans);

        // include
        int element = nums[index];
        result.push_back(element);
        solve(nums, index + 1, result, ans);
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> result;
        int index = 0;
        solve(nums, index, result, ans);
        return ans;

        
    }
};


//using bit masking
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int subcnt=(1<<n);
        vector<vector<int>> subsets;
         
        for (int mask = 0; mask < subcnt; mask++)
        {
            vector<int> subset;
            for (int i = 0; i < n; i++)
            {
                if((mask & (1<<i))!=0){
                    subset.push_back(nums[i]);
                }
            }
            subsets.push_back(subset);
            
        }
        return subsets;
    }
};
int main(){
    vector<vector<int>>ans;
    vector<int>nums;
    for (int i = 0; i < 6; i++)
    {
        cin>>nums[i];
    }
    
    
    return 0;
}
