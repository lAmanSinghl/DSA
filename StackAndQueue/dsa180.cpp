#include <bits/stdc++.h>
using namespace std;
struct ListNode2 {
    pair<int,int>val;
    ListNode2 *next;
    ListNode2 *prev;
    ListNode2() : val({0,0}), next(nullptr), prev(nullptr) {}
    ListNode2(pair<int,int>x) : val(x), next(nullptr), prev(nullptr) {}
    ListNode2(pair<int,int>x, ListNode2 *next,ListNode2 *prev) : val(x), next(next),prev(prev) {}
};
void deleteNode(ListNode2*node){
    node->prev->next=node->next;
    node->next->prev=node->prev;
    delete node;
}
ListNode2* insertStart(ListNode2*start,pair<int,int> value){
    ListNode2 *newnode=new ListNode2(value,start->next,start);
    start->next->prev=newnode;
    start->next=newnode;
    return newnode;
}

class LRUCache {
public:
    int capacity;
    ListNode2 *start;
    ListNode2 *end;
    unordered_map<int,ListNode2*>mpp;
    LRUCache(int capacity) : capacity(capacity) {
        start = new ListNode2({-1,-1});
        end = new ListNode2({-1,-1}, nullptr, start);
        start->next = end;
    }
    
    int get(int key) {
        if(mpp.find(key)!=mpp.end()){
            int val=mpp[key]->val.second;
            deleteNode(mpp[key]);
            mpp[key]=insertStart(start,{key,val});
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            deleteNode(mpp[key]);
        }else{
            capacity--;
        }
        mpp[key]=insertStart(start,{key,value});

        
        if(capacity<0){
            mpp.erase(end->prev->val.first);
            deleteNode(end->prev);
            capacity=0;
        }
    }
};