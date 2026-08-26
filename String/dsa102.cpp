#include <bits/stdc++.h>
using namespace std;

static bool comprator(pair<int,char>p1,pair<int,char>p2)
{
    if(p1.first>p2.first)return true;
    if(p1.first<p2.first)return false;
    return(p1.second>p2.second);
}
string frequencySort(string s)
{
    pair<int,char>freq[62];
    for(int i=0;i<26;i++){
        freq[i]={0,'a'+i};
    }for(int i=26;i<52;i++){
        freq[i]={0,'A'+i-26};
    }
    for(int i=52;i<62;i++){
        freq[i]={0,'0'+(i-52)};
    }

    for(char ch:s){
        if(ch>='a'&&ch<='z'){
            freq[ch-'a'].first++;
        }else if(ch>='A'&&ch<='Z'){
            freq[ch-'A'+26].first++;
        }else{
            freq[ch-'0'+52].first++;
        }
    }

    sort(freq,freq+62,comprator);
     
    string sol;
    for(auto val:freq){
         sol.append(val.first, val.second);
         if(val.first==0)break;
    }
    return sol;

}
string frequencySortUsingMap(string s)
{
    map<char, int> freq;

    for(char ch : s) {
        freq[ch]++;
    }

    vector<pair<char,int>> vec(freq.begin(), freq.end());

    sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
        return a.second > b.second;
    });

    string ans;

    for(auto p : vec) {
        ans.append(p.second, p.first);
    }

    return ans;
}
int main()
{

    return 0;
}