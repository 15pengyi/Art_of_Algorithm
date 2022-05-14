#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    int search(const vector<int> &nums, int begin, int end, int target)
    {
        if (begin > end)
        {
            return -1;
        }

        int middle(begin + (end - begin) / 2);
        if (nums[middle] == target)
        {
            return middle;
        }

        bool bisection(nums[begin] < nums[end]);
        if (!bisection || nums[middle] > target)
        {
            int ret = search(nums, begin, middle - 1, target);
            if (ret != -1 || bisection)
            {
                return ret;
            }
        }

        return search(nums, middle + 1, end, target);
    }

    int search(vector<int> &nums, int target)
    {
        return search(nums, 0, nums.size() - 1, target);
    }
};