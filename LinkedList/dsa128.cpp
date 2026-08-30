#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *bottom;

    Node(int x)
    {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};
Node *mergeTwoLists(Node *list1, Node *list2)
{

    Node *head = new Node(-1);
    Node *temp = head;
    while (list1 && list2)
    {
        if (list1->data > list2->data)
        {
            temp->bottom = list2;
            list2 = list2->bottom;
        }
        else
        {
            temp->bottom = list1;
            list1 = list1->bottom;
        }
        temp = temp->bottom;
    }
    if (list1)
    {
        temp->bottom = list1;
    }
    if (list2)
    {
        temp->bottom = list2;
    }
    return head->bottom;
}
Node *flatten(Node *head)
{
    if (!head || !head->next)
        return head;
    Node *mergedhead = flatten(head->next);
    return mergeTwoLists(head, mergedhead);
}
int main()
{

    return 0;
}