#include <bits/stdc++.h>
using namespace std;
bool isIsomorphic(string s, string t)
{
    unordered_map<char,char>mpp;
    bool used[256]={};
    for(int i=0;i<s.size();i++){
        if(mpp.find(s[i])==mpp.end()){
            if(used[(t[i])]){
              return false;
            }
            used[t[i]]=1;
           mpp[s[i]]=t[i];
        }else if(mpp[s[i]]!=t[i]){
            return false;
        }
    }
    return true;
}
int main()
{

    return 0;
}