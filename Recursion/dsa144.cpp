#include <bits/stdc++.h>
using namespace std;
void helper(int openp,int closep,int n,string &s,vector<string>&sol){
    if(openp+closep==2*n){
        sol.push_back(s);
    }
    if(openp<n){
        s.push_back('(');
        helper(openp+1,closep,n,s,sol);
        s.pop_back();
    }
    if(closep<openp){
        s.push_back(')');
        helper(openp,closep+1,n,s,sol);
        s.pop_back();
    }

}
vector<string> generateParenthesis(int n)
{
    vector<string>sol;
    string s;
    helper(0,0,n,s,sol);
}
int main()
{

    return 0;
}