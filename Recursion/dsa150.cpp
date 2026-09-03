#include <bits/stdc++.h>
using namespace std;
void helper(int index,string &digit,vector<string> &digits,int n){
    if(index==n){
        digits.push_back(digit);
        return;
    }
    if(digit.empty()||digit.back()=='1'){
        digit.push_back('0');
        helper(index+1,digit,digits,n);
        digit.pop_back();
    }
    digit.push_back('1');
    helper(index+1,digit,digits,n);
    digit.pop_back();
}
vector<string> validStrings(int n)
{
    vector<string> digits;
    string digit;
    helper(0,digit,digits,n); 
}
int main()
{

    return 0;
}