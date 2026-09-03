#include <bits/stdc++.h>
using namespace std;
void helper(vector<vector<int>> &sol, vector<int> &vec, int index, vector<int> &nums, int n)
{

    sol.push_back(vec);

    for (int i = index; i < n; i++)
    {
        if (i > index && nums[i] == nums[i - 1])
            continue;
        vec.push_back(nums[i]);
        helper(sol, vec, i + 1, nums, n);
        vec.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> sol;
    vector<int> vec;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    helper(sol, vec, 0, nums, n);
    return sol;
}
int main()
{

    return 0;
}