#include <bits/stdc++.h>
using namespace std;

vector<int> findLeaders(vector<int> nums)
{
    int max = INT_MIN;
    vector<int> result;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (max < nums[i])
        {
            max = nums[i];
            result.push_back(nums[i]);
        }
    }
    reverse(result.begin(), result.end());
    return result;
}

int betterLongestConsecutive(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;
    sort(nums.begin(), nums.end());
    int count = 1;
    int maxlen = 1;
    ;

    for (int i = 1; i < nums.size(); i++)
    {
        while (nums[i - 1] == nums[i])
        {
            i++;
            if (i >= nums.size())
            {
                return maxlen;
            }
        }

        if (nums[i - 1] == nums[i] - 1)
        {
            count++;
        }
        else
        {

            count = 1;
        }
        maxlen = max(maxlen, count);
    }
    return maxlen;
}

int OptimallongestConsecutive(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    int longest = 1;
    unordered_set<int> us;
    for (int i = 0; i < n; i++)
    {
        us.insert(nums[i]);
    }
    for (auto it : us)
    {
        if (us.find(it - 1) == us.end())
        {
            int cnt = 1;
            int x = it;
            while (us.find(x + 1) != us.end())
            {
                x++;
                cnt++;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}


int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<int> result = findLeaders(nums);

    // cout << "Leaders: ";
    // for(int x : result){
    //     cout << x << " ";
    // }

    // cout << betterLongestConsecutive(nums);
    cout << OptimallongestConsecutive(nums);

    return 0;
}