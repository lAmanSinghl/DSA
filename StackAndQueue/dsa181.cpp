#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    pair<int, int> val;
    int freq;
    ListNode *next;
    ListNode *prev;
    ListNode() : val({0, 0}), next(nullptr), prev(nullptr), freq(1) {}
    ListNode(pair<int, int> x) : val(x), next(nullptr), prev(nullptr), freq(1) {}
    ListNode(pair<int, int> x, ListNode *next, ListNode *prev) : val(x), next(next), prev(prev), freq(1) {}
};
struct List
{
    ListNode *start;
    ListNode *end;
    int amount = 0;
    List()
    {
        this->start = new ListNode({-1, -1});
        this->end = new ListNode({-1, -1}, NULL, start);
        start->next = end;
    }
    ListNode *addAtStart(pair<int, int> val)
    {
        ListNode *newnode = new ListNode(val, start->next, start);
        start->next = newnode;
        newnode->next->prev = newnode;
        amount++;
        return newnode;
    }
    void deleteNode(ListNode *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        amount--;
        delete node;
    }
};
class LFUCache
{
public:
    int capacity;
    unordered_map<int, ListNode *> mpp;
    map<int, List *> frqMpp;

    LFUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        if (mpp.find(key) == mpp.end())
            return -1;

        ListNode *temp = mpp[key];
        int currlevel = temp->freq;
        ListNode *newnode;
        if (frqMpp.find(currlevel + 1) == frqMpp.end())
        {
            List *newlist = new List;
            newnode = newlist->addAtStart(temp->val);
            frqMpp[currlevel + 1] = newlist;
        }
        else
        {
            newnode = frqMpp[currlevel + 1]->addAtStart(temp->val);
        }

        newnode->freq = temp->freq + 1;
        frqMpp[currlevel]->deleteNode(temp);
        if (frqMpp[currlevel]->amount == 0)
        {
            delete frqMpp[currlevel];
            frqMpp.erase(currlevel);
        }
        mpp[key] = newnode;
        return newnode->val.second;
    }

    void put(int key, int value)
    {
        if (capacity == mpp.size())
        {
            pair<int, List *> level = *frqMpp.begin();

            int key = level.second->end->prev->val.first;
            level.second->deleteNode(level.second->end->prev);
            mpp.erase(key);
            if (level.second->amount == 0)
            {
                delete frqMpp[level.first];
                frqMpp.erase(level.first);
            }
        }
        ListNode *newnode;
        if (mpp.find(key) == mpp.end())
        {
            if (frqMpp.find(1) != frqMpp.end())
            {
                newnode = frqMpp[1]->addAtStart({key, value});
            }
            else
            {
                frqMpp[1] = new List();
                newnode = frqMpp[1]->addAtStart({key, value});
            }
        }
        else
        {
            int currentlevel = mpp[key]->freq;

            if (frqMpp.find(currentlevel + 1) == frqMpp.end())
            {
                List *newlist = new List;
                newnode = newlist->addAtStart({key, value});
                frqMpp[currentlevel + 1] = newlist;
            }
            else
            {
                newnode = frqMpp[currentlevel + 1]->addAtStart({key, value});
            }

            newnode->freq = currentlevel + 1;
            frqMpp[currentlevel]->deleteNode(mpp[key]);

            if (frqMpp[currentlevel]->amount == 0)
            {
                delete frqMpp[currentlevel];
                frqMpp.erase(currentlevel);
            }
        }

        mpp[key] = newnode;
    }
};
