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
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{

    ListNode *head=new ListNode(-1);
    ListNode *temp=head;
    while(list1&&list2){
        if(list1->val>list2->val){
            temp->next=list2;
            list2=list2->next;
        }else{
            temp->next=list1;
            list1=list1->next;
        }
        temp=temp->next;
    }
    if(list2)temp->next=list2;
    if(list1)temp->next=list1;
    
    return head->next;
}
ListNode *sortList(ListNode *head)
{
    if(!head||!head->next)return head;
    ListNode*slow=head;
    ListNode*fast=head->next;
    while(fast&&fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    ListNode*newhead=slow->next;
    slow->next=NULL;
    head=sortList(head);
    newhead=sortList(newhead);
    return mergeTwoLists(head,newhead);
    
}
int main()
{

    return 0;
}