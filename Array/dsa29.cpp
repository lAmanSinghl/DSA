#include <bits/stdc++.h>
using namespace std;

    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int pfix=1;
        int sfix=1;
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            if(pfix==0)pfix=1;
            if(sfix==0)sfix=1;
            pfix*=nums[i];
            sfix*=nums[n-i-1];
            ans=max( ans ,max(pfix,sfix));
        }
        return ans;
    }

int main()
{
    
    return 0;
}