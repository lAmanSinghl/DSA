#include <bits/stdc++.h>
using namespace std;
int expand(string &s, int left, int right)
{
    int n = s.size();
    int cnt = 0;
    bool odd=left==right;
    while (left >= 0 && right < s.size())
    {
        if (s[left] == s[right])
        {
            cnt++;
            left--;
            right++;
        }
        else
        {
            break;
        }
    }
    if (odd){
        return 2 * cnt-1;}
    return 2 * cnt ;
}
string longestPalindrome(string s)
{
    int cnt =0;
    string str;
    for(int i=0;i<s.size();i++){
        int oddcnt=expand(s,i,i);
        if(cnt<oddcnt){
            cnt=oddcnt;
            str =s.substr(i-(cnt-1)/2,cnt);
        }
       int evencnt=expand(s,i,i+1);
        if(cnt<evencnt){
            cnt=evencnt;
            str =s.substr(i-(cnt)/2,cnt);
        }
    }
    return str;
}
int main()
{

    return 0;
}