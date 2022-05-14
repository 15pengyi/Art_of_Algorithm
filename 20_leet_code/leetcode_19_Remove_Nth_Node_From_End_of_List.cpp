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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (!head)
        {
            return head;
        }

        int size(0);
        ListNode *node = head;
        while (node)
        {
            ++size;
            node = node->next;
        }
        if (n < 1 || n > size)
        {
            return head;
        }
        if (n == size)
        {
            return head->next;
        }

        int index(1);
        ListNode *parent = head;
        ListNode *child = parent->next;
        while (child)
        {
            ++index;
            if (index == size + 1 - n)
            {
                parent->next = child->next;
            }
            else
            {
                parent = child;
            }
            child = child->next;
        }

        return head;
    }
};