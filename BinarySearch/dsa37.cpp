#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int> &nums)
{
    int low=0,high=nums.size()-1;
    if(nums[low+1]!=nums[low])return nums[low];
    if(nums[high-1]!=nums[high])return nums[high];
    low++,high--;
    while(low<=high){
        int mid=(high+low)/2;
        if(nums[mid+1]!=nums[mid] && nums[mid-1]!=nums[mid])return nums[mid];
        if((mid%2 && nums[mid-1]==nums[mid])||((!(mid%2))&&nums[mid+1]==nums[mid])){
             low=mid+1;
        }else{
            high=mid-1;
        }

    }
    return -1;
}

int main()
{
    return 0;
}