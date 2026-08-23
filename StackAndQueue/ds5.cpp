#include <bits/stdc++.h>
using namespace std;
class MinStack {
public:
    stack <long long>st;
    long long min;
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()){
            st.push(value);
            min=value;
        }else{
            if(value<min){
                st.push(2LL*value-min);
                min=value;
            }else{
                st.push(value);
            }
        }
    }
    
    void pop() {
        if(st.empty())return;
        long long n=st.top();
        st.pop();
        if(n<min){
           min=2LL*min-n;
        }
    }
    
    int top() {
        long long n=st.top();
        if(min<n){
            return n;
        }
        return min;
    }
    
    int getMin() {
        return min;
    }
};
int main()
{
    
    return 0;
}