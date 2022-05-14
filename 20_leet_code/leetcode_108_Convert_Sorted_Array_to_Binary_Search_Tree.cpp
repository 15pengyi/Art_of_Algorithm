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
    TreeNode *sortedArrayToBST(vector<int>::iterator begin, vector<int>::iterator end)
    {
        if (begin == end)
        {
            return NULL;
        }
        else
        {
            auto middle = begin + (end - begin - 1) / 2;
            TreeNode *root = new TreeNode(*middle);
            root->left = sortedArrayToBST(begin, middle);
            root->right = sortedArrayToBST(middle + 1, end);
            return root;
        }
    }

    TreeNode *sortedArrayToBST(vector<int> &num)
    {
        return sortedArrayToBST(num.begin(), num.end());
    }
};