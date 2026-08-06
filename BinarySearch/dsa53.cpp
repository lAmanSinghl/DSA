#include <bits/stdc++.h>
using namespace std;
    int rowWithMax1s(vector<vector<int>> &arr) {
        int idx=-1;
        int maxcnt=0;
        for(int i=0;i<arr.size();i++){
          int low=0;
          int high=arr[i].size()-1;
          while(low<=high){
            int mid=(low+high)/2;
            if(arr[i][mid]==1){
                high=mid-1;
            }else{
                low=mid+1;
            }
          }
          int cnt=arr[i].size()-low;
          if(cnt>maxcnt){
            maxcnt=cnt;
            idx=i;
          }
        }
        return idx;
    }
int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << rowWithMax1s(arr)+1;

    return 0;
}