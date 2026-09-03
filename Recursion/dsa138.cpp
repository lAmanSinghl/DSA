#include <bits/stdc++.h>
using namespace std;
void mapHelper(vector<vector<int>> &sol, vector<int> &vec, vector<bool> &mpp, vector<int> &nums)
{
    if (vec.size() == nums.size())
    {
        sol.push_back(vec);
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (mpp[i])
            continue;
        vec.push_back(nums[i]);
        mpp[i] = true;
        mapHelper(sol, vec, mpp, nums);
        vec.pop_back();
        mpp[i] = false;
    }
}
vector<vector<int>> permuteUsingMap(vector<int> &nums)
{
    vector<vector<int>> sol;
    vector<int> vec;
    vector<bool> mpp(nums.size(), false);
    mapHelper(sol, vec, mpp, nums);
    return sol;
}
void swapHelper(int index,vector<vector<int>>&sol,vector<int> nums,int n){
    if(index==n-1){
        sol.push_back(nums);
        return;
    }
    for(int i=index;i<n;i++){
        swap(nums[index],nums[i]);
        swapHelper(index+1,sol,nums,n);
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> sol;
    swapHelper(0, sol, nums,nums.size());
    return sol;
}

int main()
{

    return 0;
}