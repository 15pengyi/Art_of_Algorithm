#include <vector>
#include <map>
#include <string>
#include <limits>

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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        multimap<int, ListNode *> m;
        for (const auto &l : lists)
        {
            if (l)
            {
                m.insert({l->val, l});
            }
        }
        ListNode *head(nullptr), *n(nullptr);
        while (!m.empty())
        {
            auto top(m.begin());
            if (n)
            {
                n->next = new ListNode(top->first);
                n = n->next;
            }
            else
            {
                n = head = new ListNode(top->first);
            }
            ListNode *c(top->second->next);
            if (c)
            {
                m.insert({c->val, c});
            }
            m.erase(top);
        }
        return head;
    }
};