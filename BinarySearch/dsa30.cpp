#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int recusriveBinarySearch(vector<int> &nums, int target, int low, int high)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (nums[mid] == target)
        return mid;
    else if (nums[mid] < target)
    {
        return recusriveBinarySearch(nums, target, mid + 1, high);
    }
     return recusriveBinarySearch(nums, target, low, mid-1);
}

int Rsearch(vector<int> &nums, int target)
{
    return recusriveBinarySearch(nums, target,0,nums.size()-1);
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

    cout << Rsearch(nums, target);

    return 0;
}