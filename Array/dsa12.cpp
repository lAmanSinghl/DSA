#include <bits/stdc++.h>
using namespace std;

int majorityElement1(vector<int>& nums) {
    map<int,int>mpp;
    for(int i=0;i<nums.size();i++){
        mpp[nums[i]]++;
    }
    for(auto it:mpp){
        if(it.second>(nums.size()/2))return it.first;
        
    }
    return -1;    
}

int majorityElement2(vector<int>& nums) {
    int count=0;
    int majority;
    for(int i=0;i<nums.size();i++){
        if(count==0){
         majority=nums[i];
       }
       if(majority==nums[i]){
        count++;
       }else{
        count--;
       }
       
    }
    int count2=0;
    for(int i=0;i<nums.size();i++)count++;
    if(count2>nums.size()/2){
        return majority;  
    }else return -1;
}

int maxSubArray(vector<int>& nums) {
    long long sum=0,maxi=LONG_LONG_MIN;
    int start=0;
    int end;
    for(int i=0;i<nums.size();i++){
        //if you add negative you will decrease the value where as if you add positive you will be increasing it
        sum+=nums[i];

        if(maxi<sum){
            maxi=sum;
            end=i;
        }
        
        //if the total sum becomes negative there is no need to take it futher as it will only decrease the total
        if(sum<0){
            sum=0;
            start=i+1;
        }
    }
    cout<<"Strating index:"<<start<<" "<<"Ending index:"<<end<<endl;
    return maxi;
}

int main(){
   int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    // int result = majorityElement2(nums);
    // cout << "Majority Element: " << result << endl;
    int result = maxSubArray(nums);
    cout << "Major Sub Array Sum: " << result << endl;

    return 0;
}