#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> nums)
{
    long long n = nums.size();
    int Sn = (n * (n + 1)) / 2;
    int S2n = (n * (n + 1) * (2 * n + 1)) / 6;
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++)
    {
        S += nums[i];
        S2 += (long long)nums[i] * (long long)nums[i];
    }
    int rsm = S - Sn;
    int ram = (S2 - S2n) / rsm;
    return {((rsm + ram) / 2), ram - ((rsm + ram) / 2)};
}
vector<int> leetcodefindMissingAndRepeatedValues(vector<vector<int>> &grid)
{
    long long n = grid.size() * grid.size();
    int Sn = (n * (n + 1)) / 2;
    int S2n = (n * (n + 1) * (2 * n + 1)) / 6;
    long long S = 0, S2 = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; i < grid.size(); j++)
        {
            S += grid[i][j];
            S2 += (long long)grid[i][j] * (long long)grid[i][j];
        }
    }
    int rsm = S - Sn;
    int ram = (S2 - S2n) / rsm;
    return {((rsm + ram) / 2), ram - ((rsm + ram) / 2)};
}

vector<int> XORfindMissingRepeatingNumbers(vector<int> nums)
{
    long long n = nums.size();
    int xr=0;
    for (int i = 0; i < n; i++)
    {
        xr^=nums[i];
        xr^=(i+1);
    }
    int bitno=0;
    // this can also be done by bitno= xr & ~(xr-1) and ~(xr-1)== -xr
    while(1){
        if((xr && (1<<bitno))!=0){
            break;
        }
        bitno++;
    }
    int zero=0;
    int one=0;

    for(int i=0;i<n;i++){
        if((i && (1<<bitno))!=0){
            one^=nums[i];
        }else{
            zero^=nums[i];
        }
    }
    for(int i=0;i<n;i++){
        if((i && (1<<bitno))!=0){
            one^=i;
        }else{
            zero^=i;
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(nums[i]==one){
            cnt++;
        }
    }
    if(cnt==1)return {zero,one};
    else return {one,zero};
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<int> ans = findMissingRepeatingNumbers(nums);

    cout << ans[0] << " " << ans[1] << '\n';

    return 0;
}