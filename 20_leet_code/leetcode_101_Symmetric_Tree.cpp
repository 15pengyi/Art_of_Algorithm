#include <vector>
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
    bool isSymmetric(TreeNode *rootA, TreeNode *rootB)
    {
        if (!rootA && !rootB)
        {
            return true;
        }
        if (rootA && rootB && rootA->val == rootB->val)
        {
            return isSymmetric(rootA->left, rootB->right) && isSymmetric(rootA->right, rootB->left);
        }
        else
        {
            return false;
        }
    }
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }
        return isSymmetric(root->left, root->right);
    }
};