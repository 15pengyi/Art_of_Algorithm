#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }
        int size(nums.size() - 1);
        for (int i = 1; i <= size; ++i)
        {
            int count(0);
            for (const auto &n : nums)
            {
                if (n == i)
                    count++;
            }
            if (count > 1)
                return i;
        }
        return 0;
    }
};