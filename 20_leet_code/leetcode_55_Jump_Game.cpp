#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        if (nums.size() < 2)
        {
            return true;
        }
        std::vector<int> root(nums.size(), -1);
        root.back() = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; --i)
        {
            int max = std::min<int>(i + nums[i], nums.size() - 1);
            int next = i + 1;
            if (next <= max && (root[next] == next || root[next] <= max))
            {
                root[i] = i;
            }
            else
            {
                root[i] = root[next];
            }
        }
        return root.front() == 0;
    }
};