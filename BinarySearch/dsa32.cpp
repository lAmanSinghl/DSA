#include <bits/stdc++.h>
using namespace std;

// returns the index of smallest number greater then or equal to x
int lowerBound(vector<int> &nums, int x)
{
    int idx = nums.size();
    int low = 0, high = idx - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] >= x)
        {
            idx = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return idx;
}

// returns the index of smallest number greater then x
int UpperBound(vector<int> &nums, int x)
{
    int idx = nums.size();
    int low = 0, high = idx - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] > x)
        {
            idx = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return idx;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    int ldx = lowerBound(nums, target);
    if (ldx == nums.size() || nums[ldx] != target)
        return {-1 - 1};
    return {ldx, UpperBound(nums, target) - 1};
}

int firstOcur(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    int idx = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
        {
            idx = mid;
            high = mid - 1;
        }
        else if (nums[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return idx;
}

int lastOcur(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    int idx = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
        {
            idx = mid;
            low = mid + 1;
        }
        else if (nums[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return idx;
}

vector<int> searchRange2(vector<int> &nums, int target)
{
    int fcour = firstOcur(nums, target);
    if (fcour == -1)
        return {-1, -1};
    return {fcour, lastOcur(nums, target)};
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

    vector<int> ans = searchRange2(nums, target);

    cout << ans[0] << " " << ans[1];

    return 0;
}