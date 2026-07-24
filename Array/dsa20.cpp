#include <bits/stdc++.h>
using namespace std;
    //majority element 1/3
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0,cnt2=0,el1,el2;
        vector <int> ans;
        for(auto it:nums){
            if(cnt1==0 && it!=el2){
                el1=it;
                cnt1++;
                
            }else if(cnt2==0 && it!=el1){
                el2=it;
                cnt2++;
            }else if(it==el1)cnt1++;
            else if(it==el2)cnt2++;
            else if(it!=el2 && it!=el1)cnt1--,cnt2--;
            // cout<<el1<<" "<<el2<<endl;
        }
        cnt1=0,cnt2=0;
        for(auto it:nums){
            if(it==el1)cnt1++;
            if(it==el2)cnt2++;
        }
        int min=nums.size()/3;
        if(cnt1>min)ans.push_back(el1);
        if(cnt2>min)ans.push_back(el2);
        return ans;
    }

int main(){
    int x;
    cin>>x;
    vector <int> ans(x);
    for(int i=0;i<x;i++){
      cin>>ans[i];
    }
    vector <int> qs=majorityElement(ans);
    for(auto it:qs){
        cout<<it<<" ";
    }

}