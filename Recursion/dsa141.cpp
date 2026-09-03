#include <bits/stdc++.h>
using namespace std;
bool ispalindrome(string &s, int start, int end)
{
    while (start <= end)
    {
        if (s[start++] != s[end--])
            return false;
    }
    return true;
}
void helper(int ind, vector<string> &validstring, vector<vector<string>> &sol, string &s)
{
    if(ind==s.size()){
        sol.push_back(validstring);
        return;
    }
    for(int i=ind;i<s.size();i++){
        if(ispalindrome(s,ind,i)){
            validstring.push_back(s.substr(ind,i+1));
            helper(i,validstring,sol,s);
            validstring.pop_back();
        }
    }
}
vector<vector<string>> partition(string s)
{
    vector<vector<string>> sol;
    vector<string> strings;
    helper(0, strings, sol, s);
    return sol;
}
int main()
{

    return 0;
}