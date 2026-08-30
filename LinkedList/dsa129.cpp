#include <bits/stdc++.h>
using namespace std;
struct ListNode {
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

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    ListNode*head=lists[0];
    for(int i=1;i<lists.size();i++){
        head=mergeTwoLists(head,lists[i]);
    }
    return head->next;
}
ListNode *mergeKListsPriorityQueue(vector<ListNode *> &lists)
{
    if(lists.size()==0)return NULL;
    priority_queue <pair<int,ListNode *>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
    for(auto it:lists){
        if(it)pq.push({it->val,it});
        
    }
    ListNode* dummy=new ListNode(-1);
    ListNode*temp=dummy;
    while(!pq.empty()){
        ListNode *nextnode=pq.top().second;
        pq.pop();
        temp->next=nextnode;
        if(nextnode->next)pq.push({nextnode->next->val,nextnode->next});
    }
    return dummy->next;
}
int main()
{

    return 0;
}