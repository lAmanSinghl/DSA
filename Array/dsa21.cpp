#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> brutethreeSum(vector<int> &nums)
{
    int n = nums.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> els = {nums[i], nums[j], nums[k]};
                    sort(els.begin(), els.end());
                    st.insert(els);
                }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> betterthreeSum(vector<int> &nums)
{
    set<vector<int>> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        set<int> hset;
        for (int j = i + 1; j < nums.size(); j++)
        {
            int third = -(nums[i] + nums[j]);
            if (hset.find(third) != hset.end())
            {
                vector<int> temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end());
                ans.insert(temp);
            }
            hset.insert(nums[j]);
        }
    }
    vector<vector<int>> ans2(ans.begin(), ans.end());
    return ans2;
}

vector<vector<int>> optimalthreeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];

            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                ans.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;
                while (nums[j] == nums[j - 1] && j < k)
                    j++;
                while (nums[k] == nums[k + 1] && j < k)
                    k--;
            }
        }
    }
    return ans;
}

int main()
{
    int x;
    cin >> x;
    vector<int> nums(x);
    for (int i = 0; i < x; i++)
    {
        cin >> nums[i];
    }
    // vector<vector<int>> ans = brutethreeSum(nums);
    // vector<vector<int>> ans = betterthreeSum(nums);
    vector<vector<int>> ans = optimalthreeSum(nums);
    for (auto it : ans)
    {
        for (auto it2 : it)
        {
            cout << it2 << " ";
        }
        cout << endl;
    }
}