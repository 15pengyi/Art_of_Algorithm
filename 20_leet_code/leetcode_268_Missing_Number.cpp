#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int head = 0;
        while (head < nums.size())
        {
            int n = nums[head];
            if (n == head || n == -1)
            {
                head++;
            }
            else if (n == nums.size())
            {
                nums[head] = -1;
                head++;
            }
            else
            {
                int t = nums[n];
                nums[n] = n;
                nums[head] = t;
            }
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == -1)
            {
                return i;
            }
        }
        return nums.size();
    }
};