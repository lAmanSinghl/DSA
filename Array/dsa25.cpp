#include <bits/stdc++.h>
using namespace std;

void optimal1merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int left = m - 1;
    int right = 0;
    while (left >= 0 && right < n)
    {
        if (nums1[left] > nums2[right])
        {
            swap(nums1[left], nums2[right]);
            left--;
            right++;
        }
        else
        {
            break;
        }
    }
    sort(nums1.begin(), nums1.end());
}

void swapIfGreater(vector<int> &nums1, vector<int> &nums2, int ind1, int ind2)
{
    if (nums1[ind1] > nums2[ind2])
    {
        swap(nums1[ind1], nums2[ind2]);
    }
}

void optimal1merge(vector<int> &nums1, int n, vector<int> &nums2, int m)
{
    int len = n + m;
    int gap = (len / 2) + (len % 2);
    while (gap > 0)
    {
        int left = 0;
        int right = left + gap;
        while (right < len)
        {
            if (left < n && right >= n)
            {
                swapIfGreater(nums1, nums2, left, right - n);
            }
            else if (left >= n)
            {
                swapIfGreater(nums2, nums2, left-n, right - n);

            }
            else
            {
                swapIfGreater(nums1, nums1, left, right);

            }
            left++,right++;
        }
        if(gap==1)break;
        gap=(gap/2)+(gap%2);
    }
}

void mergeLeetcode(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    // for(int i=n;i<n+m-2;i++){
    //     swap(nums1[i],nums2[i-n]);
    // }
    // sort(nums1.begin(),nums2.end());
    int end1 = m - 1;
    int end2 = n - 1;
    int end = nums1.size() - 1;
    while (end1 >= 0 && end2 >= 0)
    {
        if (nums1[end1] >= nums2[end2])
        {
            swap(nums1[end1], nums1[end]);
            end--;
            end1--;
        }
        else
        {
            swap(nums2[end2], nums1[end]);
            end2--;
            end--;
        }
    }
    while (end >= 0 && end2 >= 0)
    {
        swap(nums2[end2], nums1[end]);
        end2--;
        end--;
    }
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<int> nums1(m + n);
    vector<int> nums2(n);

    for (int i = 0; i < m; i++)
        cin >> nums1[i];

    // Last n positions are already 0 by default,
    // but if your input contains them, uncomment:
    // for (int i = m; i < m + n; i++)
    //     cin >> nums1[i];

    for (int i = 0; i < n; i++)
        cin >> nums2[i];

    mergeLeetcode(nums1, m, nums2, n);

    for (int x : nums1)
        cout << x << " ";

    cout << endl;

    return 0;
}