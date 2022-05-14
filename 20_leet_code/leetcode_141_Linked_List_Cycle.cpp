#include <vector>
#include <map>
#include <string>
#include <set>
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
    bool hasCycle(ListNode *head)
    {
        if (!head)
        {
            return false;
        }

        std::set<ListNode *> visited;
        ListNode *node = head;
        do
        {
            ListNode *nodeNext = node->next;
            if (visited.count(node) == 0)
            {
                visited.insert(node);
            }
            else
            {
                return true;
            }
            node = nodeNext;
        } while (node);

        return false;
    }
};