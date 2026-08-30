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
class Solution
{
public:
    int lengthOfLoop(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        // Detect cycle
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                // Cycle found, count its length
                int cnt = 1;
                fast = fast->next;

                while (slow != fast)
                {
                    fast = fast->next;
                    cnt++;
                }

                return cnt;
            }
        }

        // No cycle
        return 0;
    }
};
int main()
{

    return 0;
}