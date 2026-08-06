#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n=matrix.size(),m=matrix[0].size();
    int row=0,col=m-1;
    while(row<n && col>=0){
        if(matrix[row][col]==target)return 1;
        else if(matrix[row][col]<target)row++;
        else col--;
    }
    return 0;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int target;
    cin >> target;

    cout << searchMatrix(matrix, target);

    return 0;
}