#include <bits/stdc++.h>
using namespace std;
struct ListNode{
    string val;
    ListNode *next;
    ListNode *prev;
    ListNode() : val(""), next(nullptr), prev(nullptr) {}
    ListNode(string x) : val(x), next(nullptr), prev(nullptr) {}
};
class BrowserHistory {
public:
    ListNode* head=NULL,*temp=NULL;
    BrowserHistory(string homepage) {
        head=new ListNode(homepage); 
        temp=head;
    }
    
    void visit(string url) {
        temp->next=new ListNode(url);
        temp->next->prev=temp;
        temp=temp->next;
    }
    
    string back(int steps) {
        for(int i=0;i<steps;i++){
            if(!temp)return NULL;
            temp=temp->prev;
        }
        return temp->val;
    }
    
    string forward(int steps) {
        for(int i=0;i<steps;i++){
            if(!temp)return NULL;
            temp=temp->next;
        }
        return temp->val;        
    }
};
int main()
{
    
    return 0;
}