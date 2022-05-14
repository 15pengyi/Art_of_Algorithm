#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (!l1 || !l2)
        {
            return l1 ? l1 : l2;
        }

        ListNode *head = NULL;
        ListNode *l = NULL;
        if (l1->val <= l2->val)
        {
            head = l = l1;
            l1 = l1->next;
        }
        else
        {
            head = l = l2;
            l2 = l2->next;
        }

        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                l->next = l1;
                l = l->next;
                l1 = l1->next;
            }
            else
            {
                l->next = l2;
                l = l->next;
                l2 = l2->next;
            }
        }
        l->next = l1 ? l1 : l2;

        return head;
    }
};