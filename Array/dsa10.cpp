#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumk1(int arr[], long long k, int n){
    //brute force
    //n³ timecomplexity
    //works for negative as well
    int maxlen=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int l=i;l<=j;l++){
                sum+=arr[l];
            }
            if(sum==k)maxlen=max(j-i+1,maxlen);
        }
    }
    return maxlen;
}

int longestSubarrayWithSumk2(int arr[], long long k, int n){
    //brute force
    //n^2 timecomplexity
    //works for negative as well
    //In This rather then iterating again and again to find sum we just add the next element 
    int maxlen=INT_MIN;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){ 
            sum+=arr[j];
            if(sum==k)maxlen=max(j-i+1,maxlen);
        }
    }
    return maxlen;
}

int longestSubarrayWithSumk3(int arr[], long long k, int n)
{
    //works for arrays with 0 and negative values
    //time complexity ordered-map==nlogn  unordermap=bestcase=n worstcase=n^2
    long long sum = 0;
    unordered_map<long long, int> preSumMap;
    int maxlen = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == k)
        {
            maxlen = max(maxlen, i + 1);
        }
        long long rem = sum - k;
        if (preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem];
            maxlen = max(maxlen, len);
        }
        if (preSumMap.find(sum) == preSumMap.end())
        {
            preSumMap[sum] = i;
        }
        
    }
    return maxlen;
}
int longestSubarrayWithSumk4(int arr[], long long k, int n){
    //works only for 0 and postivesbut has 2n time complexity and O(1) space complexity
    int left=0,right=0;
    int maxlen=0;
    long long sum=arr[0];
    while(right<=n){
        while(left<=right&&sum>k){
            sum-=arr[left];
            left++;
        }
        if(sum==k)maxlen=max(maxlen,right-left+1);
        right++;
        if(right<n)sum+=arr[right];
    }
    return maxlen;
}


int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    cout << longestSubarrayWithSumk1(arr, k, n);
    cout << longestSubarrayWithSumk2(arr, k, n);
    cout << longestSubarrayWithSumk3(arr, k, n);
    cout << longestSubarrayWithSumk4(arr, k, n);
}