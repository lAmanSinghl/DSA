#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{  
    int n = nums.size();
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        int a = nums[i];
        int more = target - a;
        cout<<"i:"<<a<<" "<<"j:"<<more<<endl;
        if (mpp.find(more) != mpp.end())
        {
            return {i, mpp[more]};
        }
        mpp[a] = i;
    }
    return {};
}

void sortColors(vector<int>& nums){
    
    int n=nums.size();
    int low=0,mid=0,high=n-1;
    while(mid<=high){
        if(nums[mid]==0){
            swap(nums[low],nums[mid]);
            low++;
            mid++;
        }else if(nums[mid]==1){
            mid++;
        }else{
            swap(nums[mid],nums[high]);
            high--;
        }
    }
}


int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    // int target;
    // cin >> target;

    // vector<int> ans = twoSum(nums, target);

    // if(ans.empty())
    //     cout << "No pair found";
    // else
    //     cout << "Indices: " << ans[0] << " " << ans[1];

    sortColors(nums);
    
    for(int i :nums){
        cout<<i<<" ";
    }

    return 0;
}