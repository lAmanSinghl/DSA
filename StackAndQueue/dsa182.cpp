#include <bits/stdc++.h>
using namespace std;

struct ListNode2 {
    int val;
    ListNode2 *next;
    ListNode2 *prev;
    ListNode2() : val(0), next(nullptr),prev(nullptr){}
    ListNode2(int x) : val(x), next(nullptr),prev(nullptr) {}
    ListNode2(int x, ListNode2 *next, ListNode2 *prev) : val(x), next(next),prev(prev) {}
};

class FreqStack {
public:
    ListNode2*start=new ListNode2(-1);
    ListNode2*end=new ListNode2(-1);
    unordered_map<int,stack<ListNode2 *>>mpp;
    unordered_map<int,int>valinstack;
    int maxfreq;
    FreqStack() {
        start->next=end;
        end->prev=start;
    }
    
    void push(int val) {
        ListNode2 *newnode=new ListNode2(val,end,start);
        start->next=newnode;
        start=start->next;
        if(valinstack.find(val)==valinstack.end()){
            mpp[1].push(start);
            valinstack[val]=1;
            

        }else{
            int prevstack=valinstack[val];
            mpp[prevstack+1].push(start);
            valinstack[val]=prevstack+1;
        }
        maxfreq=max(maxfreq,valinstack[val]);
    }
    
    int pop() {
        ListNode2* value= mpp[maxfreq].top();
        if(value==start){
            start=start->prev;
        }
        value->prev->next=value->next;
        value->next->prev=value->prev;
        mpp[maxfreq].pop();
        valinstack[value->val]--;
        if(valinstack[value->val]==0){
            valinstack.erase(value->val);
        }
        if(mpp[maxfreq].empty()){
            mpp.erase(maxfreq);
            maxfreq--;
        }
        int val=value->val;
        return val;
    }
};
int main()
{
    
    return 0;
}