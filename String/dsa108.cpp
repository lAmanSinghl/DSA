#include <bits/stdc++.h>
using namespace std;
int beautySum(string s)
{
    int ans = 0;

    for (int i = 0; i < s.size(); i++)
    {
        int freq[26] = {};
        int maxi=0,mini=INT_MAX;
        for (int j = i; j < s.size(); j++)
        {
            freq[s[j]-'a']++;
            for(int k=0;k<26;k++){
                if(freq[k]>0){
                    maxi=max(maxi,freq[k]);
                    mini=min(mini,freq[k]);
                }
            }
            ans+=maxi-mini;
        }
    }
    return ans;
}
int main()
{

    return 0;
}