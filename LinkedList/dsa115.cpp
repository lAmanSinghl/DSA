#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
    bool isPalindrome(ListNode* head) {
    if(!head||!head->next)return true;
    ListNode *mid=head;
    ListNode *last=head;
    while(last&&last->next){
        mid=mid->next;
        last=last->next->next;
    }
    ListNode* prev=mid;
    mid=mid->next;
    prev->next=NULL;
    while(mid){
        ListNode* nextnode=mid->next;
        mid->next=prev;
        prev=mid;
        mid=nextnode;
    }

    ListNode *temp=head;
    while(prev){
        if(prev->val!=temp->val){
            return false;
        }
        prev=prev->next;
        temp=temp->next;
    }
    return true;
    }
int main()
{

    return 0;
}