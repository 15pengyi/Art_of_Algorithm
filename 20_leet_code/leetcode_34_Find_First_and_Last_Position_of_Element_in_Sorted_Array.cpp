#include <vector>
#include <map>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        auto lower(lower_bound(nums.begin(), nums.end(), target));
        if (lower == nums.end() || *lower > target)
        {
            return vector<int>{-1, -1};
        }
        auto upper(upper_bound(lower + 1, nums.end(), target));
        return vector<int>{
            (int)(lower - nums.begin()),
            (int)(upper - 1 - nums.begin())};
    }
};