#include <bits/stdc++.h>
using namespace std;
vector<int> nextSmallerEle(vector<int> &arr)
{
    stack<int> st;
    int n = arr.size();
    vector<int> sol(n);
    for (int i =0; i < n; i++)
    {
        while (!st.empty() && st.top() > arr[i])
        {
            st.pop();
        }

        sol[i]=(st.empty() ? -1 : st.top());
        st.push(arr[i]);
    }
    return sol;
}
int main()
{

    return 0;
}