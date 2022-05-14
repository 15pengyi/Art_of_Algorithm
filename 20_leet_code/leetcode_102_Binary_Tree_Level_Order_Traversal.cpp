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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (!root)
        {
            return std::vector<std::vector<int>>();
        }

        std::list<std::vector<int>> ret;
        std::vector<int> values;
        std::list<TreeNode *> list(1, root);
        for (auto node : list)
        {
            values.push_back(node->val);
        }
        ret.push_back(values);

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
                for (auto node : list)
                {
                    values.push_back(node->val);
                }
                ret.push_back(values);
            }
        }
        return std::vector<std::vector<int>>(ret.begin(), ret.end());
    }
};