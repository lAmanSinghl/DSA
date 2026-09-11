#include <bits/stdc++.h>
using namespace std;
void helper(int index,vector<int>&subset,vector<vector<int>> &sol,vector<int> &nums){
    if(index==nums.size()){
        sol.push_back(subset);
        return;
    }
    subset.push_back(nums[index]);
    helper(index+1,subset,sol,nums);
    subset.pop_back();
    helper(index+1,subset,sol,nums);

}
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> sol;
    vector<int>subset;
    helper(0,subset,sol,nums);
    return sol;
}
int main()
{

    return 0;
}