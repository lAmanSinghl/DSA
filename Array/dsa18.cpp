#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
       map<int,int> mpp;
       mpp[0]=1;
       int presum=0,cnt=0;
       for(int i=0;i<nums.size();i++){
        presum+=nums[i];
        int remove=presum-k;
        cnt+=mpp[remove];
        mpp[presum]+=1;
       }
       for(auto it:mpp){
        cout<<it.first<<"-"<<it.second<<endl;
       }
       return cnt;
}

int main(){
    int n,k;
    cin>>n;

    vector<int> nums(n);

    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    cin>>k;

    int ans=subarraySum(nums,k);

    cout<<"Number of subarrays with sum "<<k<<" = "<<ans<<endl;

    return 0;
}