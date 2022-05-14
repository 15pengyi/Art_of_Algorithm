#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            int num(nums[i]);
            while (num > 0 && num <= nums.size() && num != i + 1 && num != nums[num - 1])
            {
                nums[i] = nums[num - 1];
                nums[num - 1] = num;
                num = nums[i];
            }
            if (num != i + 1)
            {
                nums[i] = 0;
            }
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
            {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};