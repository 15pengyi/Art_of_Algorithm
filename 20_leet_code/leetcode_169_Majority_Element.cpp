#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int number(nums.front());
        int count(0), index(0);
        while (index + 1 < nums.size())
        {
            int first(nums[index]);
            int second(nums[index + 1]);
            if (first == second)
            {
                if (count == 0)
                {
                    number = first;
                }
                if (first == number)
                {
                    count += 2;
                }
                else
                {
                    count -= 2;
                }
            }
            index += 2;
        }
        if (count > 0)
        {
            return number;
        }
        else
        {
            return nums.back();
        }
    }
};