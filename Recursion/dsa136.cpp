#include <bits/stdc++.h>
using namespace std;

void helper(vector<int> &arr,vector<int> &sol,int sum,int index){
    if(index==arr.size()){
        sol.push_back(sum);
        return;
    }
    helper(arr,sol,sum+arr[index],index+1);
    helper(arr,sol,sum,index+1);
}
vector<int> subsetSums(vector<int> &arr)
{
    vector<int>sol;
    helper(arr,sol,0,0);
    sort(sol.begin(),sol.end());
    return sol;

}
int main()
{

    return 0;
}