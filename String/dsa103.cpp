#include <bits/stdc++.h>
using namespace std;
int maxDepth(string s)
{
    int maxi=0;
    int cnt=0;
    for(int i =0;i<s.size();i++){
        if(s[i]=='('){
            cnt++;
        }else if(s[i]==')'){
            cnt--;
        }else{
            continue;
        }
        maxi=max(maxi,cnt);
    }
    return maxi;
}
int main()
{

    return 0;
}