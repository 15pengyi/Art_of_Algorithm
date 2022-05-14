#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        vector<int> numbers(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            numbers[(i + k) % nums.size()] = nums[i];
        }
        nums = numbers;
    }
};