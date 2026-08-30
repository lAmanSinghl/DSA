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

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if(!head||!head->next&&n==1)return NULL;
    ListNode *temp=head;
    ListNode *node=head;
    for(int i=0;i<n;i++){
        temp=temp->next;
    }
    if(temp==NULL){
      return head->next;
    }
    while(temp->next){
        temp=temp->next;
        node=node->next;
    }
    node->next=node->next->next;
    return head;
}

int main()
{

    return 0;
}