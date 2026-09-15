#include <bits/stdc++.h>
using namespace std;

long long calcSumSubarrayMins(vector<int> &nums){
    int n=nums.size();
    vector<int>nse(n);
    vector<int>psee(n);
    stack<int>nsest;
    stack<int>pseest;

    for(int i=0;i<n;i++){
        while(!pseest.empty()&&nums[pseest.top()]>nums[i])pseest.pop();
        psee[i]=pseest.empty()?-1:pseest.top();
        pseest.push(i);

        while(!nsest.empty()&&nums[nsest.top()]>=nums[n-i-1])nsest.pop();
        nse[n-i-1]=nsest.empty()?n:nsest.top();
        nsest.push(n-i-1);
    }
    
    long long total=0;
    for(int i=0;i<n;i++){
        total=total+1LL*(i-psee[i])*(nse[i]-i)*nums[i];
    }
    return total;
}
long long calcSumSubarrayMaxs(vector<int> &nums){
    int n=nums.size();
    vector<int>nle(n);
    vector<int>plee(n);
    stack<int>nlest;
    stack<int>pleest;

    for(int i=0;i<n;i++){
        while(!pleest.empty()&&nums[pleest.top()]<nums[i])pleest.pop();
        plee[i]=pleest.empty()?-1:pleest.top();
        pleest.push(i);

        while(!nlest.empty()&&nums[nlest.top()]<=nums[n-i-1])nlest.pop();
        nle[n-i-1]=nlest.empty()?n:nlest.top();
        nlest.push(n-i-1);
    }
    
    long long total=0;
    for(int i=0;i<n;i++){
        total=total+1LL*(i-plee[i])*(nle[i]-i)*nums[i];
    }
    return total;
}

long long subArrayRanges(vector<int> &nums)
{
  return calcSumSubarrayMaxs(nums)-calcSumSubarrayMins(nums);
}
int main()
{

    return 0;
}