#include <bits/stdc++.h>
using namespace std;

int missingNumberUsingXOR(int arr[], int n){
    int xor1 = 0, xor2 = 0;
    int n2 = n - 1;
    for (int i = 0; i < n2; i++)
    {
        xor2 = xor2 ^ arr[i];
        xor1 = xor1 ^ (i + 1);
    }
    xor1 = xor1 ^ n;
    return xor1 ^ xor2;
}

int missingNumberUsingSum(int arr[], int n){
    // Since it involves n², it may cause data overflow, so the XOR version is better.
    int sum = n * (n + 1) / 2;
    for (int i = 0; i < n - 1; i++)
    {
        sum -= arr[i];
    }
    return sum;
}

int consecutiveOnes(int arr[], int n)
{
    int ones = 0;
    int big = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1){
            ones++;
            if (big < ones){
                big = ones;
            }
        }
        
        if (arr[i] == 0){
            ones = 0;
        }
    }
    
    return big;
}

int getSingleElement(int arr[], int n){
    int xor1=0;
    for(int i=0;i<n;i++){
        xor1^=arr[i];
    }
    return xor1;
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

    //    cout<<missingNumberUsingXOR(arr,n)<<endl;
    //    cout<<missingNumberUsingSum(arr,n);

    // cout << consecutiveOnes(arr, n);

    cout<<getSingleElement(arr,n);

    //    for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    //    }
}