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
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *odd(head), *even(head->next);
        ListNode *first(odd), *second(even);
        ListNode *nFirst(second->next);
        ListNode *nSecond(nFirst == NULL ? NULL : nFirst->next);
        first->next = nFirst;
        second->next = nSecond;
        while (nFirst != NULL && nSecond != NULL)
        {
            first = nFirst;
            second = nSecond;
            nFirst = second->next;
            nSecond = nFirst == NULL ? NULL : nFirst->next;
            first->next = nFirst;
            second->next = nSecond;
        }
        if (nFirst != NULL)
        {
            nFirst->next = even;
        }
        else
        {
            first->next = even;
        }
        return odd;
    }
};