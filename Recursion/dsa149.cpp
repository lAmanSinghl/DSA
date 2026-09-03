#include <bits/stdc++.h>
using namespace std;

void helper(int n,stack<int> &st){
    if(st.empty()){
      st.push(n);
      return;
    }
    int x=st.top();
    st.pop();
    helper(n,st);
    st.push(x);
}
void reverseStack(stack<int> &st)
{
    if(st.empty())return;
    int n=st.top();
    st.pop(); 
    reverseStack(st);
    helper(n,st);
}

int main()
{
    
    return 0;
}