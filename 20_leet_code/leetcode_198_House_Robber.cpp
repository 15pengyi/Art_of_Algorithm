#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        std::vector<int> max(nums.size() + 1);
        max[1] = nums[0];
        for (int i = 2; i <= nums.size(); ++i)
        {
            max[i] = std::max<int>(max[i - 1], max[i - 2] + nums[i - 1]);
        }
        return max.back();
    }
};