#include <bits/stdc++.h>
using namespace std;
int findmax(vector <int> piles){
   int maxi=INT_MIN;
   for(int i=0;i<piles.size();i++){
    maxi=max(maxi,piles[i]);
   }
   return maxi;
}
int findT(vector <int> piles,int h){
    long long total=0;
    for(auto it:piles){
        total+=ceil((double)it/(double)h);
    }
    return total;
}
int minEatingSpeed(vector<int> &piles, int h)
{
    int low=1,high=findmax(piles);
    while(low<=high){
        int mid=(low+high)/2;
        int totalT=findT(piles,mid);
        if(totalT>h){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return high;
}

int main()
{
    int n;
    cin >> n;

    vector<int> piles(n);
    for (int i = 0; i < n; i++)
    {
        cin >> piles[i];
    }

    int h;
    cin >> h;

    cout << minEatingSpeed(piles, h);

    return 0;
}