#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        if (nums.empty())
        {
            return -1;
        }
        int left(0), right(nums.size() - 1);
        while (left < right)
        {
            int middle((left + right) / 2);
            if (nums[middle] > nums[middle + 1])
            {
                right = middle;
            }
            else
            {
                left = middle + 1;
            }
        }
        return left;
    }
};