#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
        for(int i=1;i<matrix.size();i++){
           for(int j=0;j<i;j++){
            swap(matrix[i][j],matrix[j][i]);
           }
        }
        for(int i=0;i<matrix.size();i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
}
int main(){
  int r, c;
    cin >> r >> c;

    vector<vector<int>> matrix(r, vector<int>(c));

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> matrix[i][j];
        }
    }

    rotate(matrix);

    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}