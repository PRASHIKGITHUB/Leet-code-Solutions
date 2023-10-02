class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        int size = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> ans;
        int count = 1;
        for (int i = 0; i < size - 1; i++)
        {
            int j = i + 1;
            if (arr[i] == arr[j])
            {
                count++;
            }
            else
            {
                ans.push_back(count);
                count = 1;
            }
            if (i == size - 2)//This ensures that the count of last element in the sorted array gets added in the ans vector
            {
                ans.push_back(count);
            }
        }

        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        sort(ans.begin(), ans.end());//This will sort the ans vector
        for (int i = 0; i < ans.size() - 1; i++)
        {
            if (ans[i] == ans[i + 1])
            {
                return false;
            }
        }
        return true;
    }
};