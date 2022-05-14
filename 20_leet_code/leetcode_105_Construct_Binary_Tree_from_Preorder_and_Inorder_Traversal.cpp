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
    TreeNode *buildTree(
        std::vector<int>::iterator inorderBegin, std::vector<int>::iterator inorderEnd,
        std::vector<int>::iterator preorderBegin, std::vector<int>::iterator preorderEnd)
    {
        if (inorderBegin == inorderEnd || preorderBegin == preorderEnd)
        {
            return NULL;
        }

        int pivot = *preorderBegin;
        int size = 0;
        for (auto i = inorderBegin; i != inorderEnd; ++i)
        {
            if (*i == pivot)
            {
                break;
            }
            ++size;
        }

        TreeNode *root = new TreeNode(pivot);
        root->left = buildTree(inorderBegin, inorderBegin + size, preorderBegin + 1, preorderBegin + 1 + size);
        root->right = buildTree(inorderBegin + size + 1, inorderEnd, preorderBegin + 1 + size, preorderEnd);
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return buildTree(inorder.begin(), inorder.end(), preorder.begin(), preorder.end());
    }
};