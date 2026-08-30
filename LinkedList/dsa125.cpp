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
    if (!head || !head->next)
        return head;
    ListNode *newhead = reverseList(head->next);
    ListNode *front = head->next;
    front->next = head;
    head->next = NULL;
    return newhead;
}
ListNode *findkthnode(ListNode *head, int k)
{
    for (int i = 1; i < k; i++)
    {
        if (!head)
            return NULL;
        head = head->next;
    }
    return head;
}
ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *temp = head, *nextnode = NULL, *prevnode = NULL;
    while (temp)
    {
        ListNode *kthnode = findkthnode(temp, k);
        if (kthnode == NULL)
            return head;
        nextnode = kthnode->next;
        kthnode->next = NULL;
        reverseList(temp);
        if (prevnode)
            prevnode->next = kthnode;
        temp->next = nextnode;
        if (temp == head)
            head = kthnode;
        prevnode = temp;
        temp = nextnode;
    }
    return head;
}
int main()
{

    return 0;
}