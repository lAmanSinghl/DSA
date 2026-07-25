#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> brutefourSum(vector<int> &nums, int target)
{
    int n = nums.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += +nums[l];
                    if (sum == target)
                    {
                        vector<int> el = {nums[i], nums[j], nums[k], nums[l]};
                        sort(el.begin(), el.end());
                        st.insert(el);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> betterfourSum(vector<int> &nums, int target)
{
    int n = nums.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            set<int> hset;
            for (int k = j + 1; k < n; k++)
            {
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                int t = target - sum;
                if (hset.find(t) != hset.end())
                {
                    vector<int> el = {nums[i], nums[j], nums[k], (int)t};
                    sort(el.begin(), el.end());
                    st.insert(el);
                }

                hset.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> optimalfourSum(vector<int> &nums, int target)
{
    
    int n = nums.size();
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        if(i!=0 && nums[i]==nums[i-1])continue;
        for (int j = i + 1; j < n; j++)
        {
            if(j!=i+1 && nums[j]==nums[j-1])continue;

            int k = j + 1, l = n - 1;

            while (k < l)
            {
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                sum += nums[l];
                if (target == sum)
                {
                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    k++;l--;
                    while(k<l && nums[k]==nums[k-1])k++;
                    while(k<l && nums[l]==nums[l+1])l--;
                }
                else if (target > sum)
                {
                    k++;
                }else{
                    l--;
                }
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
    // vector<vector<int>> ans = brutefourSum(nums, 0);
    // vector<vector<int>> ans = betterfourSum(nums, 1);
    vector<vector<int>> ans = optimalfourSum(nums, 0);
    for (auto it : ans)
    {
        for (auto it2 : it)
        {
            cout << it2 << " ";
        }
        cout << endl;
    }
}