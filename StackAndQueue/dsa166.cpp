#include <bits/stdc++.h>
using namespace std;
int calculate(string s)
{
    stack<pair<int, string>> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
            continue;
        if (s[i] == '(')
        {
            st.push({0, "("});
        }
        if (s[i] > '0' && s[i] < '9')
        {
            int num = s[i] - '0';
            while (i + 1 < s.size() && s[i + 1] > '0' && s[i + 1] < '9')
            {
                num = num * 10 + (s[i + 1] - '0');
                i++;
            }
            st.push({num, "X"});
        }
        if (s[i] == '+')
        {
            st.push({0, "+"});
        }
        if (s[i] == '-')
        {
            st.push({0, "-"});
        }
        if (s[i] == ')')
        {
            int sum = 0;
            while (st.top().second != "(")
            {
                int num1 = st.top().first;
                st.pop();
                num1 = st.top().second == "+" ? num1 : -1 * num1;
                st.pop();
                sum += num1;
            }
            st.pop();
            st.push({sum, "X"});
        }
    }
    int sum = 0;
    while (!st.empty())
    {

        int num1 = st.top().first;
        st.pop();
        if(!st.empty()){
        num1 = st.top().second == "+" ? num1 : -1 * num1;
        st.pop();
         }
        sum += num1;
    }
    return sum;
}
int main()
{

    return 0;
}