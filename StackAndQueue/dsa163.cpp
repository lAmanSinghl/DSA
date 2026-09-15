#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    stack <char> st;
    for(int i=0;i<s.size();i++){
        if(!st.empty()&&st.top()==s[i]){
            st.pop();
        }else{
            if(s[i]=='('){
                st.push(')');
            }else if(s[i]=='{'){
                st.push('}');
            }else if(s[i]=='['){
                st.push(']');
            }
        }
    }
    return st.empty();
}

int main()
{

    return 0;
}