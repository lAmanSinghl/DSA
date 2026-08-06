#include <bits/stdc++.h>
using namespace std;

int possible(vector<int> &nums, int mid){
int cnt=1,sum=0;
for(auto it:nums){
    sum+=it;
    if(sum>mid){
      cnt++;
      sum=it;
    }
    
}
return cnt;
}

int findPages(vector<int> &nums, int m)  {
    int low=*max_element(nums.begin(),nums.end()),high=accumulate(nums.begin(),nums.end(),0);
    while(low<=high){
        int mid=(low+high)/2;
        int number=possible(nums,mid);
        if(number>m){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }   
    return low;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int m;
    cin >> m;

    cout << findPages(nums, m);

    return 0;
}