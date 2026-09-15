#include <bits/stdc++.h>
using namespace std;
string removeKdigits(string num, int k)
{
    if (num.size() <= k)
        return "0";
    string sol;
    stack<char> st;
    int i = 0;
    while (i < num.size())
    {
        while (!st.empty() && st.top() > num[i] && k > 0)
        {
            st.pop();
            k--;
        }
        st.push(num[i]);
        i++;
    }
    while (k > 0)
    {
        st.pop();
        k--;
    }
    //Hence now k must be 0
    while (!st.empty())
    {
        sol += st.top();
        st.pop();
    }
    reverse(sol.begin(), sol.end());
    while (sol[k] == '0' && k < sol.size())
    {
        k++;
    }
    sol = sol.substr(k, sol.size() - k);
    return sol == "" ? "0" : sol;
}
int main()
{

    return 0;
}