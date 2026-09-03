#include <bits/stdc++.h>
using namespace std;
void helper(string digits,int index,string &s,vector<string>&sol){
    if(index==digits.size()){
        sol.push_back(s);
        return;
    }
    for(int i=0;i<(digits[index]=='7'||digits[index]=='9'?4:3);i++){
        s.push_back('a'+(((digits[index])-'2')*3+i+(digits[index]>'7'?1:0)));
        helper(digits,index+1,s,sol);
        s.pop_back();
    }
}
vector<string> letterCombinations(string digits)
{
    vector<string>sol;
    string s;
    helper(digits,0,s,sol);
    return sol;
}

int main()
{

    return 0;
}