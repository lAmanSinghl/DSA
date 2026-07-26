#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr, int start, int mid, int end)
{
    int cnt=0;
    vector<int> sorted(end - start + 1);

    int i = start;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            sorted[k++] = arr[i++];
        }
        else
        {
            cnt+=(mid-i+1);
            sorted[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        sorted[k++] = arr[i++];
    }

    while (j <= end)
    {
        sorted[k++] = arr[j++];
    }

    for (int i = start; i <= end; i++)
    {
        arr[i] = sorted[i - start];
    }
    return cnt;
}

int merge_sort(vector<int> &arr, int start, int end)
{
    int cnt=0;
    if (start >= end)
        return 0;

    int mid = start + (end - start) / 2;

    cnt+=merge_sort(arr, start, mid);
    cnt+=merge_sort(arr, mid + 1, end);

    cnt+=merge(arr, start, mid, end);
    return cnt;
}

long long int numberOfInversions(vector<int> nums)
{
 return merge_sort(nums,0,nums.size()-1);

}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << numberOfInversions(nums);

    return 0;
}