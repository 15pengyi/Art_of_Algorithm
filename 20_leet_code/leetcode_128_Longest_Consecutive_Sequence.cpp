#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_map<int, int> m;
        int max = 0;
        for (auto i : nums)
        {
            if (m[i])
            {
                continue;
            }
            int left = m[i - 1];
            int right = m[i + 1];
            int length = m[i] = m[i + right] = m[i - left] = right + left + 1;
            max = std::max<int>(max, length);
        }
        return max;
    }
};