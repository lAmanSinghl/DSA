#include <bits/stdc++.h>
using namespace std;

int findKthPositive(vector<int> &arr, int k)
{
    int low=0,high=arr.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if((arr[mid]-(mid+1))<k){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return high+k+1;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << findKthPositive(arr, k);

    return 0;
}