#include <bits/stdc++.h>
using namespace std;
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> sol;
    deque<int> deq;
    for (int i = 0; i < nums.size(); i++)
    {
        while (!deq.empty() && nums[deq.back()] < nums[i])
            deq.pop_back();
        deq.push_back(i);
        if (i + 1 >= k)
        {
            if (i - k + 1 > deq.front())
                deq.pop_front();
            sol.push_back(nums[deq.front()]);
        }
    }
    return sol;
}
int main()
{

    return 0;
}