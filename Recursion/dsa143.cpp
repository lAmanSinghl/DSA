#include <bits/stdc++.h>
using namespace std;

void helper(vector<int>&nums,string &s,int k,int fact){
    if(nums.size()==0)return;
    int i=k/fact;
    s+=to_string(nums[i]);
    nums.erase(nums.begin()+i);
    helper(nums,s,k%fact,fact/nums.size());
}
string getPermutation(int n, int k)
{
    vector<int>nums;
    string s;
    int fact=1;
    for(int i=1;i<n;i++){
        nums.push_back(i);
        fact*=i;
    }
    nums.push_back(n);
    helper(nums,s,k-1,fact);
    return s;
}
int main()
{

    return 0;
}