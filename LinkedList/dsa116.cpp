#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};
Node *addOne(Node *head)
{
    Node *temp = head;
    Node *before9=NULL;
    while (temp)
    {
        if (temp->data != 9)
        {
            before9 = temp;
        }
        temp = temp->next;
    }
    if (!before9)
    {
        Node *newnode = new Node(1, head);
        while (head)
        {
            head->data = 0;
            head = head->next;
        }
        return newnode;
    }
    while (before9)
    {
        before9->data = (before9->data + 1) % 10;
        before9 = before9->next;
    }
    return head;
}
int getcarry(Node *head)
{
    // my intution
    //  if (head->next == NULL)
    //  {
    //      if (head->data == 9)
    //      {
    //          head->data = 0;
    //          return 1;
    //      }
    //      head->data++;
    //      return 0;
    //  }
    //  int carry = getcarry(head->next);
    //  if (carry)
    //  {
    //      if (head->data == 9)
    //      {
    //          head->data = 0;
    //          return 1;
    //      }
    //      head->data++;
    //      return 0;
    //  }
    //  else
    //  {
    //      return 0;
    //  }
    if (!head)
        return 1;
    int carry = getcarry(head->next);
    head->data=head->data+carry;
    if(head->data==10){
        head->data=0;
        return 1;
    }
    return 0;
}
Node *addOneRecursive(Node *head)
{
    int carry = getcarry(head);
    if (carry)
    {
        Node *newnode = new Node(1);
        newnode->next = head;
        return newnode;
    }
    else
    {
        return head;
    }
}
int main()
{

    return 0;
}