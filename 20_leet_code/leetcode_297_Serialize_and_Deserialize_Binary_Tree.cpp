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

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root, vector<int> &size)
    {
        size[0] = size[1] = 0;
        if (root == NULL)
        {
            return ":";
        }

        string structure(""), inorder("");
        if (root->left)
        {
            vector<int> s(2, 0);
            vector<string> left(split(serialize(root->left, s), ":"));
            structure += left[0] + ',';
            inorder += left[1] + ',';
            size[0] = s[0] + 1 + s[1];
        }
        inorder += to_string(root->val) + ',';
        if (root->right)
        {
            vector<int> s(2, 0);
            vector<string> right(split(serialize(root->right, s), ":"));
            structure += right[0] + ',';
            inorder += right[1] + ',';
            size[1] = s[0] + 1 + s[1];
        }
        structure = to_string(size[0]) + ',' + structure;

        return string(
            structure.substr(0, structure.size() - 1) + ':' +
            inorder.substr(0, inorder.size() - 1));
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        vector<int> size(2, 0);
        return serialize(root, size);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(const vector<int> &s, const vector<int> &in)
    {
        if (in.size() != s.size())
        {
            return NULL;
        }
        if (in.size() == 0)
        {
            return NULL;
        }
        TreeNode *root = new TreeNode(in[s.front()]);
        root->left = deserialize(
            vector<int>(s.begin() + 1, s.begin() + 1 + s.front()),
            vector<int>(in.begin(), in.begin() + s.front()));
        root->right = deserialize(
            vector<int>(s.begin() + 1 + s.front(), s.begin() + s.size()),
            vector<int>(in.begin() + s.front() + 1, in.begin() + in.size()));
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        vector<string> info(split(data, ":"));
        if (info.size() != 2)
        {
            return NULL;
        }

        vector<int> s(0);
        for (const auto &str : split(info[0], ","))
        {
            if (!str.empty())
                s.push_back(stoi(str));
        }

        vector<int> in(0);
        for (const auto &str : split(info[1], ","))
        {
            if (!str.empty())
                in.push_back(stoi(str));
        }

        return deserialize(s, in);
    }

    vector<string> split(const string &s, const string &d)
    {
        vector<string> v(0);
        int l(0);
        for (int r = 0; (r = s.find_first_of(d, l)) != string::npos; l = r + 1)
        {
            v.push_back(s.substr(l, r - l));
        }
        v.push_back(s.substr(l));
        return v;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));