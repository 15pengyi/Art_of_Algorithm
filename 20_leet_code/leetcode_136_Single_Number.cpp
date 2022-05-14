#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int single(0);
        for (auto &n : nums)
        {
            single ^= n;
        }
        return single;
    }
};