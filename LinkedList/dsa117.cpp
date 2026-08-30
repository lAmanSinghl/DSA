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
//As tempa and tempb will at some point be eventualy equal, try dry running it to understand well
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *tempa = headA;
    ListNode *tempb = headB;
    while (tempa != tempb)
    {
        tempa = tempa?tempa->next:headA;
        tempb = tempb?tempb->next:headB;
        
    }
    return tempa;
}
int main()
{

    return 0;
}