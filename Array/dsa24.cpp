#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> brutemergeOverlappingIntervals(vector<vector<int>> nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {

        int start = nums[i][0];
        int end = nums[i][1];
        //This condition skips intervals that have already been merged
        if (!ans.empty() && ans.back()[1] >= end)
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j][0] <= end)
            {
                end = max(end, nums[j][1]);
            }
            else
            {
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
}

vector<vector<int>> optimalmergeOverlappingIntervals(vector<vector<int>> nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
     if(ans.empty() || ans.back()[1]<nums[i][0]){
        ans.push_back({nums[i][0],nums[i][1]});
     }
     else{
        ans.back()[1]=max(ans.back()[1],nums[i][1]);
     }
    }
    return ans;
}

int main()
{
    int x;
    cin >> x;
    vector<vector<int>> nums(x, vector<int>(2));
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> nums[i][j];
        }
    }
    // vector<vector<int>> ans = brutemergeOverlappingIntervals(nums);
    vector<vector<int>> ans = optimalmergeOverlappingIntervals(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}