#include <bits/stdc++.h>
using namespace std;
struct Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};
Node *removeDuplicates(Node *headRef)
{
Node *temp = headRef;

while (temp && temp->next) {
    if (temp->next->data == temp->data) {
        Node *nextnode = temp->next;

        while (nextnode && nextnode->data == temp->data)
            nextnode = nextnode->next;

        temp->next = nextnode;

        if (nextnode)
            nextnode->prev = temp;
    } 
    else {
        temp = temp->next;
    }
}

return headRef;
}
int main()
{

    return 0;
}