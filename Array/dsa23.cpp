#include <bits/stdc++.h>
using namespace std;

int numberOfSubarrayWithXORk(vector<int> nums, int k)
{
    int xr = 0;
    int cnt = 0;
    map<int, int> mpp;
    mpp[xr]++;
    for (int i = 0; i < nums.size(); i++)
    {
        xr = xr ^ nums[i];
        int x = xr ^ k;
        //mpp[x] Returns the count if x is found; otherwise, returns 0
        cnt += mpp[x];
        mpp[xr]++;
    }
    return cnt;
}

int main()
{
    int x;
    cin >> x;
    vector<int> nums(x);
    for (int i = 0; i < x; i++)
    {
        cin >> nums[i];
    }
    cout << numberOfSubarrayWithXORk(nums, 6);
}