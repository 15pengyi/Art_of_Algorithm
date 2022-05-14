#include <vector>
#include <map>
#include <string>
#include <deque>
#include <limits>

using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> buffer;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i)
        {
            while (!buffer.empty() && nums[i] >= nums[buffer.back()])
            {
                buffer.pop_back();
            }
            buffer.push_back(i);

            if (i >= k - 1)
            {
                res.push_back(nums[buffer.front()]);
            }
            if (buffer.front() <= i - k + 1)
            {
                buffer.pop_front();
            }
        }
        return res;
    }
};