#include <bits/stdc++.h>
using namespace std;

// Greedily checks if we can place k cows such that
// the minimum distance between any two cows is at least 'mingap'.
int possible(vector<int> &nums, int k, int mingap)
{
    int placed = 1, prev = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] - prev >= mingap)
        {
            placed++;
            prev = nums[i];
        }

        // Successfully placed all cows.
        if (placed == k)
            return 1;
    }

    return 0;
}

int aggressiveCows(vector<int> &nums, int k)
{
    // Sort the stall positions so that distances are in increasing order.
    sort(nums.begin(), nums.end());
    int low = 1;
    // The maximum possible minimum distance cannot exceed
    // ceil((last stall - first stall) / (k - 1)).
    int high = (nums[nums.size() - 1] - nums[0] + k - 2) / (k - 1);

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (possible(nums, k, mid))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
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

    int k;
    cin >> k;

    cout << aggressiveCows(nums, k);

    return 0;
}