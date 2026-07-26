#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;


void merge(vector<int> &arr, int start, int mid, int end)
{
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
}

int countPairs(vector<int> &arr, int low, int mid,int high){
    int cnt=0;
    int right=mid+1;
    for(int i=low;i<=mid;i++){
        while(right<=high && arr[i]>2LL*arr[right])right++;
        cnt+=(right-(mid+1));
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
    cnt+=countPairs(arr,start,mid,end);
    merge(arr, start, mid, end);
    return cnt;
}


int reversePairs(vector<int> &nums)
{
  return  merge_sort(nums,0,nums.size()-1);;
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

    cout << reversePairs(nums);

    return 0;
}