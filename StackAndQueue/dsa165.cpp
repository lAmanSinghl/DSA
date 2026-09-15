#include <bits/stdc++.h>
using namespace std;
class MinStack {
public:
    int min=INT_MIN;
    stack<long long>st;
    MinStack() {
        
    }
    
    void push(int value) {
        if(value>=min){
            st.push(value);
        }else{
            st.push(2*value-min);
            min=value;
        }
    }
    
    void pop() {
        if(min>st.top()){
            min=2*min-st.top();
        }
        st.pop();
    }
    
    int top() {
        if(min>st.top()){
            return 2*min-st.top();
        }
        return st.top();
    }
    
    int getMin() {
        return min;
    }
};int main()
{
    
    return 0;
}