#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int> &nums)
{
    int n = nums.size();
    int positive = 0;
    int negative = 1;
    vector<int> result(n);
    for (int i = 0; i < n; i++)
    {
        if (nums[i] < 0)
        {
            result[negative] = nums[i];
            ;
            negative += 2;
        }
        else
        {
            result[positive] = nums[i];
            positive += 2;
        }
    }
    return result;
}
void nextPermutation(vector<int> &nums)
{
    int index = -1;
    for (int i = nums.size() - 1; i > 0; i--)
    {
        if (nums[i] > nums[i - 1])
        {
            index = i - 1;
            break;
        }
    }
    if (index == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }
    for (int i = nums.size() - 1; i > index; i--)
    {
        if (nums[index] < nums[i])
        {
            swap(nums[i], nums[index]);
            break;
        }
    }
    reverse(nums.begin() + index + 1, nums.end());
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
    // vector <int> x=rearrangeArray(nums);
    nextPermutation(nums);
    for (auto y : nums)
    {
        cout << y << " ";
    }
}