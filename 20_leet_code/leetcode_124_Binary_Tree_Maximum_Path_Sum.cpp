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
    int maxPathSumSingle(TreeNode *root, int &maxPath)
    {
        if (root == NULL)
        {
            return 0;
        }
        int left(maxPathSumSingle(root->left, maxPath));
        int right(maxPathSumSingle(root->right, maxPath));
        int val(max(max(left, right), 0));
        maxPath = max(maxPath, root->val + max(val, left + right));
        return root->val + val;
    }

    int maxPathSum(TreeNode *root)
    {
        int maxPath(numeric_limits<int>::min());
        maxPathSumSingle(root, maxPath);
        return maxPath;
    }
};