#include <bits/stdc++.h>
using namespace std;

int findmax(vector<vector<int>> &mat ,int n,int m){
    int max=INT_MIN;
    int idx=-1;
    for(int i=0;i<n;i++){
        if(max<mat[i][m]){
            max=mat[i][m];
            idx=i;
        }
    }
    return idx;
}

vector<int> findPeakGrid(vector<vector<int>> &mat)
{
    int n=mat.size(),m=mat[0].size();
    int low=0,high=m-1;
  
    while(low<=high){
        int mid=(low+high)/2;
        int row=findmax(mat,n,mid);
        int left=(mid-1)>=0?mid-1:-1;
        int right=(mid+1)<n?mid+1:-1;
        if(mat[row][mid]>left &&mat[row][mid]>right )return {row,mid};
        else if(mat[row][mid]<left)high=mid-1;
        else low=mid+1;
    }
    return {-1,-1};
}
int main()
{

    return 0;
}