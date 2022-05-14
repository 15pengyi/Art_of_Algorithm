#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <limits>

using namespace std;

struct RandomListNode
{
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution
{
public:
    RandomListNode *copyRandomList(RandomListNode *head)
    {
        if (head == NULL)
        {
            return NULL;
        }

        RandomListNode *n(NULL), *newN(NULL);
        RandomListNode *newHead = new RandomListNode(head->label);
        vector<RandomListNode *> newM(1, newHead);
        unordered_map<RandomListNode *, int> p({{head, 0}});
        for (n = head->next, newN = newHead; n != NULL; n = n->next)
        {
            newN->next = new RandomListNode(n->label);
            newN = newN->next;
            newM.push_back(newN);
            int s(p.size());
            p[n] = s;
        }
        for (n = head, newN = newHead; n != NULL; n = n->next, newN = newN->next)
        {
            newN->random = n->random == NULL ? NULL : newM[p[n->random]];
        }
        return newHead;
    }
};