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
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (root == NULL)
        {
            return vector<int>(0);
        }
        vector<int> left(inorderTraversal(root->left));
        left.push_back(root->val);
        vector<int> right(inorderTraversal(root->right));
        left.insert(left.end(), right.begin(), right.end());
        return left;
    }
};