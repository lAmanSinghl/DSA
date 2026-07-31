#include <bits/stdc++.h>
using namespace std;
int possible(vector<int> &bloomDay, int m, int k,int d){
    int cnt=0,b=0;
    int n=bloomDay.size();
    for(int i=0;i<n;i++){
        if(bloomDay[i]<=d){
            cnt++;
        }else{
            b+=cnt/k;
            cnt=0;
        }
    }
    b+=cnt/k;
    if(b>=m)return 1;
    return 0;

}
int minDays(vector<int> &bloomDay, int m, int k)
{
  if((long long)m*(long long)k>bloomDay.size())return -1;
  int low=*min_element(bloomDay.begin(),bloomDay.end()),high=*max_element(bloomDay.begin(),bloomDay.end());
  while(low<=high){
    int mid=(low+high)/2;
    if(possible(bloomDay, m, k,mid)){
        high=mid-1;
    }else{
        low=mid+1;
    }
  }
  return low;
}
int main()
{
    int n;
    cin >> n;

    vector<int> bloomDay(n);
    for (int i = 0; i < n; i++)
    {
        cin >> bloomDay[i];
    }

    int m, k;
    cin >> m >> k;

    cout << minDays(bloomDay, m, k);

    return 0;
}