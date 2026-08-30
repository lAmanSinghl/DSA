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
ListNode *reverseList(ListNode *head)
{
    if(!head||!head->next)return head;
    ListNode* prev=NULL;
    while(head){
        ListNode * nextnode=head->next;
        head->next=prev;
        prev=head;
        nextnode=head;
    }
    return prev;
}
//This make a new LL rather then reversing the links of orignal one
ListNode * helper(ListNode*prev,ListNode*head){
    if(!head)return prev;
    ListNode *nextnode=head->next;
    return helper(head,nextnode);
}
ListNode *recursivereverseList(ListNode *head)
{
    return helper(NULL,head);
}
ListNode *recursivereverseListStriver(ListNode *head)
{
    if(!head||!head->next)return head;
    ListNode *newhead=recursivereverseListStriver(head->next);
    ListNode* front=head->next;
    front->next=head;
    head->next = NULL;
    return newhead;
}
int main()
{

    return 0;
}