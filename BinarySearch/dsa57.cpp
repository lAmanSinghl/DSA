#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int>& arr, int value)
{
    int low = 0, high = arr.size()-1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] <= value)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int findit(vector<vector<int>> &mat, int n, int m, int value)
{
    int cnt=0;
    for(int i=0;i<n;i++){
        cnt+=upperBound(mat[i],value);
    }
    return cnt;
}

int median(vector<vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size();
    int low = INT_MAX, high = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (low > mat[i][0])
        {
            low = mat[i][0];
        }
        if (high < mat[i][m - 1])
        {
            high = mat[i][m - 1];
        }
    }
    int req = (n * m) / 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int lesserEqual = findit(mat, n, m, mid);
        if(lesserEqual<=req)low=mid+1;
        else high=mid-1;
    }
    return low;
}

int main()
{

    return 0;
}