#include <bits/stdc++.h>
using namespace std;
vector<int> asteroidCollision(vector<int> &asteroids)
{
    stack<int>st;
    for(int i=0;i<asteroids.size();i++){
        if(asteroids[i]>0){
            st.push(asteroids[i]);
            continue;
        }
        int absAstroid=abs(asteroids[i]);
        while(!st.empty()&&st.top()>0&&asteroids[i]<0){
            if(st.top()>=absAstroid){
                break;
            }else{
                st.pop();
            }
        }
        if(st.empty()||st.top()<0){
            st.push(asteroids[i]);
        }
    }
    vector<int>sol(st.size());
    for(int i=st.size()-1;i>=0;i++){
        sol[i]=st.top();
        st.pop();
    }
    return sol;
}
int main()
{

    return 0;
}