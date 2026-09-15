#include <bits/stdc++.h>
using namespace std;
int celebrity(vector<vector<int>> &mat)
{
        if(mat.size()==1)return 0;
        int low=0;
        int high=mat.size();
        while(low<high){
            if(mat[low][high]==1){
                low++;
            }else if(mat[high][low]==1){
                high--;
            }else{
                low++;
                high--;
            }
        }
        if(low>high)return -1;
        for(int i=0;i<mat.size();i++){
            if(low=i)continue;
            if(mat[low][i]==1)return -1;
        }
        return low;
}
int main()
{

    return 0;
}