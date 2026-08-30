#include <bits/stdc++.h>
using namespace std;
struct Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};
vector<vector<int>> givenSumPairs(Node *head, int target)
{
    vector<vector<int>> sol;
    if (!head)
        return sol;
    Node *left = head;
    Node *right = head;

    while (right->next)
        right = right->next;
    while (left->data < right->data)
    {
        if (left->data + right->data == target)
        {
            sol.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
        else if (left->data + right->data < target)
        {
            left = left->next;
        }
        else
        {
            right = right->prev;
        }
    }
    return sol;
}
int main()
{

    return 0;
}