#include <bits/stdc++.h>
using namespace std;

int combination(int n,int r){
    int x=min(r,n-r);
    long long result=1;;
    for(int i=1;i<=x;i++){
       result*=n-i+1;
       result/=i;
    }
    return result;
}

int pascalSingelCell(int row ,int col){
   return combination(row-1,col-1);
}

vector<int> generateRow(int rowNo){
    long long ans=1;
    vector <int> result;
    result.push_back(1);
    for(int i=1;i<rowNo;i++){
        ans*=(rowNo-i);
        ans/=i;
        result.push_back(ans);
    }
    return result;
}

vector<vector<int>> generate(int numRows) {
        vector <vector <int>> result;
        for(int i=0;i<numRows;i++){
            result.push_back(generateRow(i+1));
        }
        return result;
}

int main(){
 int n,r;

    cin>>n;

    cin>>r;

    int ans = pascalSingelCell(n,r);

    cout<<"Combination (nCr) = "<<ans<<endl;

    return 0;
}