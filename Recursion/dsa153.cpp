#include <bits/stdc++.h>
using namespace std;
void helper(long long index, string &num, long long preval, long long currval, int target, string &s, vector<string> &sol)
{
    if (index == num.size())
    {
        if (target == currval)
        {
            sol.push_back(s);
        }
        return;
    }
    int oldSize = s.size();
    for (long long i = index; i < num.size(); i++)
    {
        string temp = num.substr(index, i - index + 1);
        if ((temp[0] == '0') && (i - index + 1) != 1)
            continue;
        long long val = 0;
        for (int i = 0; i < temp.size(); i++)
        {
            val = val * 10 + (temp[i] - '0');
        }
        if (val > INT_MAX)
            continue;
        if (index == 0)
        {
            s += temp;

            helper(i + 1, num, val, val, target, s, sol);

            s.resize(oldSize);
            continue;
        }
        s.push_back('+');
        s += (temp);
        helper(i + 1, num, val, currval + val, target, s, sol);
        s.resize(oldSize);

        s.push_back('-');
        s += (temp);
        helper(i + 1, num, -1 * val, currval - val, target, s, sol);
        s.resize(oldSize);

        s.push_back('*');
        s += (temp);
        helper(i + 1, num, preval * val, currval - preval + preval * val, target, s, sol);
        s.resize(oldSize);
    }
}
vector<string> addOperators(string num, int target)
{
    vector<string> sol;
    string s;
    helper(0, num, 0, 0, target, s, sol);
    return sol;
}
int main()
{

    return 0;
}