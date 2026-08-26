#include <bits/stdc++.h>
using namespace std;
bool rotateString(string s, string goal)
{
    int cnt = 0;
    int n = goal.size();
    if (n != s.size())
        return false;
    string news = s + s;
    for (int i = 0; i < news.size(); i++)
    {
        int x = i;
        for (int j = 0; j < goal.size(); j++)
        {
            if (news[x + j] == goal[j])
            {
                if (n - 1 == j)
                {
                    return true;
                }
            }
            else
            {
                break;
            }
        }
    }
    return false;
}
int main()
{

    return 0;
}