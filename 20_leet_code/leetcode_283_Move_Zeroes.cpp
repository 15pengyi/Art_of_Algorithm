#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int index(0);
        while (index < nums.size() && nums[index] != 0)
        {
            ++index;
        }
        for (int i = index + 1; i < nums.size(); ++i)
        {
            int &number(nums[i]);
            if (number != 0)
            {
                nums[index++] = number;
                number = 0;
            }
        }
    }
};