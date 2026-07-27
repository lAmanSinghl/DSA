#include <bits/stdc++.h>
using namespace std;

int findMinRotatedSortedArraySearch(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    int min2 = INT_MAX;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        // This condition is an optimization.
        // If the current search range is already sorted, then the first element
        // (nums[low]) is the minimum in this range, so we can return it immediately.
        if (nums[low] <= nums[high])
        {
            return min(min2, nums[low]);
        }

        if (nums[low] <= nums[mid])
        {
            min2 = min(min2, nums[low]);
            low = mid + 1;
        }
        else
        {
            // The left half is not sorted, so the pivot (and the minimum) lies in
            // the left half. We include nums[mid] because it could itself be the
            // minimum element.
            min2 = min(min2, nums[mid]);
            high = mid - 1;
        }
    }
    return min2;
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

    cout << findMinRotatedSortedArraySearch(nums, 0);

    return 0;
}