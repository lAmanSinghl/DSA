#include <bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    int min2 = INT_MAX;
    int idx=-1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[low] <= nums[high])
        {
            if(min2>nums[low]){
                min2=nums[low];
                idx=low;
            }
            break;
        }

        if (nums[low] <= nums[mid])
        {
            if(min2>nums[low]){
                min2=nums[low];
                idx=low;
            }
            low = mid + 1;
        }
        else
        {
            if(min2>nums[mid]){
                min2=nums[mid];
                idx=mid;
            }
            high = mid - 1;
        }
    }
    return idx;
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

    cout << findKRotation(nums, 0);

    return 0;
}