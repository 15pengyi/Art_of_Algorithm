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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == NULL || headB == NULL)
        {
            return NULL;
        }

        int sizeA = 1;
        for (ListNode *t = headA; t != NULL; t = t->next)
        {
            sizeA++;
        }

        int sizeB = 1;
        for (ListNode *t = headB; t != NULL; t = t->next)
        {
            sizeB++;
        }

        ListNode *nodeA(headA), *nodeB(headB);
        if (sizeA < sizeB)
        {
            nodeA = headB;
            nodeB = headA;
        }
        for (int i = abs(sizeA - sizeB) - 1; i >= 0; --i)
        {
            nodeA = nodeA->next;
        }

        while (nodeA != NULL && nodeB != NULL)
        {
            if (nodeA == nodeB)
            {
                return nodeA;
            }
            nodeA = nodeA->next;
            nodeB = nodeB->next;
        }
        return NULL;
    }
};