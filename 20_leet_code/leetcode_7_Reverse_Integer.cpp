#include <string>
#include <vector>
#include <limits>

using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        int sign(x > 0 ? 1 : -1);
        long long y = (long long)x * sign;
        vector<int> digits;
        while (y > 0)
        {
            digits.push_back(y % 10);
            y = y / 10;
        }
        long long result(0);
        for (auto d : digits)
        {
            result = result * 10 + d;
        }
        result = result * sign;
        return result > numeric_limits<int>::max() || result < numeric_limits<int>::min() ? 0 : result;
    }
};
