#include <bits/stdc++.h>
using namespace std;

void betterSetZeroes(vector<vector<int>>& matrix) {
    vector <int> row(matrix.size(),0);
    vector <int> col(matrix[0].size(),0);

    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            if(matrix[i][j]==0){
                row[i]=1;
                col[j]=1;
            }

        }
    }
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            if(row[i]||col[j]){
                matrix[i][j]=0;
            }
        }
    }
    
}

void OptimalsetZeroes(vector<vector<int>>& matrix) {
    int col0=1;
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            if(matrix[i][j]==0){
                matrix[i][0]=0;
                if(j!=0){
                    matrix[0][j]=0;
                }else{
                    col0=0;
                }
            }
        }
    }    
    
    for(int i=matrix.size()-1;i>0;i--){
        for(int j=matrix[i].size()-1;j>0;j--){
            if((!matrix[0][j])||(!matrix[i][0])){
                matrix[i][j]=0;
            }
        }
    }
    if(matrix[0][0]==0){
        for(int i=0;i<matrix[0].size();i++){
            
            matrix[0][i]=0;
        }
    }
    if(col0==0){
        for(int i=0;i<matrix.size();i++){
            matrix[i][0]=0;
        }
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

    // betterSetZeroes(matrix);
    OptimalsetZeroes(matrix);

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
  
}