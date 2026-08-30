#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
Node *copyRandomList(Node *head)
{
    unordered_map<Node*,Node*>mp;
    Node*temp=head;
    while(temp){
        mp[temp]=new Node(temp->val);
        temp=temp->next;
    }
    temp=head;
    while(temp){
        mp[temp]->next=mp[temp->next];
        mp[temp]->random=mp[temp->random];
    }
    return mp[head];
}
Node *copyRandomListOptimal(Node *head)
{
    Node*temp=head;
    while(temp){
        Node*newlistnode=new Node(temp->val);
        Node*nexttemp=temp->next;
        temp->next=newlistnode;
        newlistnode->next=nexttemp;
        temp=temp->next->next;
    }
    temp=head;
    while(temp){
        temp->next->random=temp->random?temp->random->next:NULL;
        temp=temp->next->next;
    }
    temp=head;
    Node*copyhead=temp->next;
    Node*copytemp=copyhead;
    while(temp){
        temp->next=temp->next->next;
        copytemp->next=temp->next?temp->next->next:NULL;
        temp=temp->next;
        copytemp=copytemp->next;
    }
    return copyhead;
}
int main()
{

    return 0;
}