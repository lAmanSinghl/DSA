#include <bits/stdc++.h>
using namespace std;
//returns the index of smallest number greater then or equal to x
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

//returns the index of smallest number greater then x
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

// returns the index of the largest number less than or equal to x
int floor(vector<int> &nums, int x)
{
    int idx = nums.size();
    int low = 0, high = idx - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] <= x)
        {
            idx = mid;
            low = mid + 1;
        }
        else
        {
            high= mid - 1;
        }
    }
    return idx;
}

//lower bound is ceil here
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
     return {nums[floor(nums,x)],nums[lowerBound( nums,x)]};
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

    int x;
    cin >> x;

    cout << lowerBound(nums, x)<<endl;
    cout << UpperBound(nums, x)<<endl;
    //This stl deos the same thing c++ specific
    cout <<lower_bound(nums.begin(),nums.end(),x)-nums.begin()<<endl;
    cout <<upper_bound(nums.begin(),nums.end(),x)-nums.begin()<<endl;
    vector<int> ans=getFloorAndCeil(nums,x);
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}