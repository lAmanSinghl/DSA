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
ListNode *sortListwith012(ListNode *head)
{
    if(!head&&!head->next)return head;
    ListNode *zerohead=new ListNode(-1);
    ListNode *zero=zerohead;
    ListNode *onehead=new ListNode(-1);
    ListNode *one=onehead;
    ListNode *twohead=new ListNode(-1);
    ListNode *two=twohead;
    ListNode *temp=head;
    while(temp){
        if(temp->val==0){
            zero->next=temp;
            zero=zero->next;
        }else if(temp->val==1){
            one->next=temp;
            one=one->next;
        }else{
            two->next=temp;
            two=two->next;
        }
        temp=temp->next;
    }
    zero->next=onehead->next?onehead->next:twohead->next;
    one->next=twohead->next;
    two->next=NULL;
    return zerohead->next;
}

int main()
{

    return 0;
}