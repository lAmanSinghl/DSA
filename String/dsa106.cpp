#include <bits/stdc++.h>
using namespace std;

int atmost(string s, int k)
{
    int left=0;
    int right=0;
    int freq[26]={};
    int distinct=0;
    int cnt=0;
    while(right<s.size()){
        if(freq[s[right]]==0) {
            distinct++;
        }
        freq[s[right++]]++;
        while(distinct>k){
            if(freq[s[left]]==1){
            distinct--;
            freq[s[left++]]--;
            }else{
            freq[s[left++]]--;   
            }
        }
        cnt+=right-left;
    }
    return cnt;
    
}
int countSubstrings(string s, int k)
{
    return atmost(s, k) - atmost(s, k - 1);
}

int main()
{

    return 0;
}