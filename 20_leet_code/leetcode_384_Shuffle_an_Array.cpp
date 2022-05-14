#include <vector>
#include <map>
#include <string>
#include <limits>
#include <ctime>

using namespace std;

class Solution
{
public:
    vector<int> nums_;

    Solution(vector<int> nums) : nums_(nums)
    {
        std::srand(std::time(0));
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
        return nums_;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        vector<int> nums(nums_.begin(), nums_.end());
        for (int i = 0; i < nums.size(); ++i)
        {
            int r(rand() % (nums.size() - i));
            int t(nums[i]);
            nums[i] = nums[i + r];
            nums[i + r] = t;
        }
        return nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */