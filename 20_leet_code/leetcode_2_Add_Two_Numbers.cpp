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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *parent(nullptr), *result(nullptr);
        while (l1 || l2 || (parent && parent->val >= 10))
        {
            ListNode *l3(new ListNode());
            if (parent)
            {
                parent->next = l3;
            }
            else
            {
                result = l3;
            }
            if (l1)
            {
                l3->val += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                l3->val += l2->val;
                l2 = l2->next;
            }
            if (parent)
            {
                l3->val += parent->val / 10;
                parent->val = parent->val % 10;
            }
            parent = l3;
        }
        return result;
    }
};