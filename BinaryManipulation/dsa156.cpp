#include <bits/stdc++.h>
using namespace std;
vector<int> singleNumber3(vector<int> &nums)
{
    int check=0;
    for(auto it:nums){
        check^=it;
    }
    while(check&(check-1)!=0){
       check=check&(check-1);
    }
    int one=0,two=0;
    for(auto it:nums){
        if(it&check){
            one =one^it;
        }else{
            two=two^it;
        }
    }
    return {one,two};
}
int main()
{

    return 0;
}