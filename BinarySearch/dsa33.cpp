#include <bits/stdc++.h>
using namespace std;

int rotatedSortedArraySearch(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
            return mid;


        // This condition determines which half of the array is sorted.
        // We then check whether the target lies in the sorted half.
        // If it does, we continue searching there; otherwise, we search the other half.
        if (nums[low] <= nums[mid])
        {
            if (nums[mid] >= target && nums[low] <= target)
            {
                high = mid - 1;
            } 
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (nums[mid] <= target && nums[high] >= target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}

//repetation allowed
bool rotatedSortedArraySearch2(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
            return nums[mid]==target;
         //---------------------------------------------------------------//
         if(nums[low]==nums[mid]&&nums[mid]==nums[high]){
            low++;
            high--;
            continue;
         }
        //----------------------------------------------------------------//
        // This condition determines which half of the array is sorted.
        // We then check whether the target lies in the sorted half.
        // If it does, we continue searching there; otherwise, we search the other half.
        if (nums[low] <= nums[mid])
        {
            if (nums[mid] >= target && nums[low] <= target)
            {
                high = mid - 1;
            } 
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (nums[mid] <= target && nums[high] >= target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return 0;
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

    int target;
    cin >> target;

    cout << rotatedSortedArraySearch2(nums, target);

    return 0;
}