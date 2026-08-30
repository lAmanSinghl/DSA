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

//Find the starting node of the loop 
ListNode *detectCycle(ListNode *head)
{
  ListNode*slow=head;
  ListNode*fast=head;
  while(fast&&fast->next){
    slow=slow->next;
    fast=fast->next->next;
    if(slow==fast){
        fast=head;
        while(fast!=slow){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
  }
  return NULL;
}
int main()
{

    return 0;
}
