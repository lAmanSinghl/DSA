#include <bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string> &strs)
{
    string s=strs[0];
    for(int i=1;i<strs.size();i++){
        int j=0;
        while(j<s.size()&&j<strs[i].size()&&s[j]==strs[i][j]){
            j++;
        }
        if(j==0)return "";
        s=strs[i].substr(0,j);
    }
    return s;
}
string StriversWaylongestCommonPrefix(vector<string> &strs)
{
   sort(strs.begin(),strs.end());
   string first=strs[0];
   string last=strs[strs.size()-1];
   int mins=min(first.size(),last.size());
   int i=0;
   for( i;i<mins;i++){
    if(first[i]!=last[i]){
        break;
    }
   }
   return first.substr(0,i);
}
int main()
{

    return 0;
}