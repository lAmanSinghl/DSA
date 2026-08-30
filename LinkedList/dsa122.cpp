#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};

Node *deleteAllOccurOfX(Node *head, int x)
{
    while(head&&head->data==x)head=head->next;
    head->prev=NULL;
    Node*temp=head;
    while(temp){
        if(temp->data=x){
            temp->prev->next=temp->next;
            if(temp->next)temp->next->prev=temp->prev;
        }else{
            temp=temp->next;
        }
    }
    return head;
}
Node *deleteAllOccurOfX(Node *head, int x)
{
    Node*temp=head;
    while(temp){
        if(temp->data==x){
            if(temp==head){
                head=head->next;
            }
            Node*prevnode=temp->prev;
            Node*nextnode=temp->next;
            if(prevnode)prevnode->next=nextnode;
            if(nextnode)nextnode->prev=prevnode;
            free(temp);
            temp=nextnode;
        }else{
            temp=temp->next;
        }
    }
    return head;
}
int main()
{

    return 0;
}