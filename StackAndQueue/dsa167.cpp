#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> mpp;
    stack<int> st;
    for (int i = nums2.size() - 1; i >= 0; i--)
    {

        while (!st.empty() && st.top() <= nums2[i])
        {
            st.pop();
        }
        mpp[nums2[i]] = st.empty() ? -1 : st.top();
        st.push(nums2[i]);
    }
    vector<int> sol;
    for (auto it : nums1)
    {
        sol.push_back(mpp[it]);
    }
    return sol;
}
int main()
{

    return 0;
}