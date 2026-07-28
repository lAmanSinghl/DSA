#include <bits/stdc++.h>
using namespace std;
    //Returns one of the peak element in the array it works for even with 1 peak
    int findPeakElement(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        if(high==0)return nums[0];
        if(nums[low]>nums[low+1])return nums[low];
        if(nums[high]>nums[high-1])return nums[high];
        low++,high--;
        while(low<=high){
           int mid=(low+high)/2;
           if(nums[mid]>nums[mid-1]&&nums[mid]>nums[mid+1])return nums[mid];
           else if(nums[mid]>nums[mid+1])high=mid-1;
           else low=mid+1;
        }
        return -1;
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


    cout << findPeakElement(nums);

    return 0;
}