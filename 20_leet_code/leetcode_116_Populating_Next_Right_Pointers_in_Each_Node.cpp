#include <vector>
#include <list>
#include <map>
#include <string>
#include <limits>

using namespace std;

struct TreeLinkNode
{
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution
{
public:
    void connect(TreeLinkNode *root)
    {
        if (root)
        {
            std::list<TreeLinkNode *> list(1, root);
            while (!list.empty())
            {
                std::vector<TreeLinkNode *> queue;
                for (TreeLinkNode *node : list)
                {
                    if (node->left)
                    {
                        queue.push_back(node->left);
                    }
                    if (node->right)
                    {
                        queue.push_back(node->right);
                    }
                }
                for (int i = 1; i < queue.size(); ++i)
                {
                    queue[i - 1]->next = queue[i];
                }
                list.assign(queue.begin(), queue.end());
            }
        }
    }
};