#include <vector>
#include <list>
#include <map>
#include <string>
#include <limits>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (!root)
        {
            return std::vector<std::vector<int>>();
        }

        bool zig = true;
        std::list<std::vector<int>> ret;
        std::vector<int> values;
        std::list<TreeNode *> list(1, root);
        if (zig)
        {
            for (auto i = list.begin(); i != list.end(); ++i)
            {
                values.push_back((*i)->val);
            }
        }
        else
        {
            for (auto i = list.rbegin(); i != list.rend(); ++i)
            {
                values.push_back((*i)->val);
            }
        }
        ret.push_back(values);
        zig = !zig;

        while (!list.empty())
        {
            std::vector<TreeNode *> queue;
            for (auto node : list)
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
            list.assign(queue.begin(), queue.end());

            if (list.size())
            {
                values.clear();
                if (zig)
                {
                    for (auto i = list.begin(); i != list.end(); ++i)
                    {
                        values.push_back((*i)->val);
                    }
                }
                else
                {
                    for (auto i = list.rbegin(); i != list.rend(); ++i)
                    {
                        values.push_back((*i)->val);
                    }
                }
                ret.push_back(values);
                zig = !zig;
            }
        }
        return std::vector<std::vector<int>>(ret.begin(), ret.end());
    }
};