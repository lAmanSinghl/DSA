#include <bits/stdc++.h>
using namespace std;

int possible(vector<int>&nums, int threshold,int mid){
    int sum=0;
    for(auto it:nums){
      sum+=((it+mid-1)/mid);
    }
    if(sum<=threshold)return 1;
    return 0;
}

int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,high=*max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(nums,threshold,mid)){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
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

    int threshold;
    cin >> threshold;

    cout << smallestDivisor(nums, threshold);

    return 0;
}