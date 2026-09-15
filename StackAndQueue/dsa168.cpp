#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElements(vector<int> &nums)
{
    stack<int> st;
    int n = nums.size();
    vector<int> sol(n);
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        int j = i % n;
        while (!st.empty() && st.top() <= nums[j])
        {
            st.pop();
        }
        if (i < n)
        {
            sol[i]=(st.empty() ? -1 : st.top());
        }
        st.push(nums[j]);
    }
    return sol;
}
int main()
{

    return 0;
}