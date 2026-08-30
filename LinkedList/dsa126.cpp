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

ListNode *rotateRight(ListNode *head, int k)
{
        if(!head||k==0)return head;
    ListNode *last = head;
    int cnt = 1;
    while (last->next)
    {
        last = last->next;
        cnt++;
    }
    k = cnt % k;
    if(k==0)return head;
    last->next=head;
    for(int i=0;i<k+1;i++){
        last=last->next;
    }
    ListNode *newhead=last->next;
    last->next=NULL;
    return newhead;
}
int main()
{

    return 0;
}