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
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *rHead(reverseList(head->next));
        ListNode *rTail(head->next);
        rTail->next = head;
        head->next = NULL;
        return rHead;
    }
};