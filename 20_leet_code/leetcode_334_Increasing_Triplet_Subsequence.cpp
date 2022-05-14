#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        vector<int> s(0);
        for (int i = 0; i < nums.size(); ++i)
        {
            auto it = lower_bound(s.begin(), s.end(), nums[i]);
            if (it == s.end())
            {
                s.push_back(nums[i]);
            }
            else
            {
                *it = nums[i];
            }
            if (s.size() > 2)
                return true;
        }
        return false;
    }
};