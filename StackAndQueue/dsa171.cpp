#include <bits/stdc++.h>
using namespace std;
int sumSubarrayMins(vector<int> &arr)
{
    int n=arr.size();
    long long modulo=1e9+7;
    //next smallest element
    vector<int>nse(n);
    //previous smallest and equal element;
    vector<int>psee(n);
    stack<int>nsest;
    stack<int>psest;
    for(int i=0;i<n;i++){
        while(!nsest.empty()&&arr[n-i-1]<arr[nsest.top()]){
            nsest.pop();
        }
        while(!psest.empty()&&arr[i]<=arr[psest.top()]){
            psest.pop();
        }
        nse[n-i-1]=nsest.empty()?n:nsest.top();
        psee[i]=psest.empty()?-1:psest.top();
        psest.push(i);
        nsest.push(n-i-1);
    }
    long long sum=0;
    for(int i=0;i<n;i++){
    sum=(sum+1LL*(nse[i]-i)*(i-psee[i])*arr[i])%modulo;
    }
    return sum;
}
int main()
{

    return 0;
}