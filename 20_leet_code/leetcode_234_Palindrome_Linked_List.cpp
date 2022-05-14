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
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return true;
        }
        int count(0);
        for (ListNode *i = head; i != NULL; i = i->next)
        {
            count++;
        }

        ListNode *middle(head), *prev(NULL);
        int half(count / 2);
        for (int i = 0; i < half; ++i)
        {
            ListNode *next = middle->next;
            middle->next = prev;
            prev = middle;
            middle = next;
        }
        if (count % 2 == 1)
        {
            middle = middle->next;
        }

        while (middle != NULL && prev != NULL && middle->val == prev->val)
        {
            middle = middle->next;
            prev = prev->next;
        }
        return middle == NULL && prev == NULL;
    }
};