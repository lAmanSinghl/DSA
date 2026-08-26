#include <bits/stdc++.h>
using namespace std;
string removeOuterParentheses(string s)
{
    string sol="";
    int cnt=0;
    for(int i=0;i<s.size();i++){
        if(cnt==0&&s[i]=='('){
         cnt++;
       }else if(cnt>0&&s[i]=='('){
        sol+=s[i];
        cnt++;
       }else if(cnt>1&&s[i]==')'){
        sol+=s[i];
        cnt--;
       }else if(cnt==1&&s[i]==')'){
        cnt--;
       }
    }
    return sol;
}
int main()
{

    return 0;
}