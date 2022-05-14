#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        double prev(x), delta(x);
        while (delta >= 1e-6)
        {
            double cur(prev - (prev * prev - x) / (2 * prev));
            delta = abs(cur - prev);
            prev = cur;
        }
        return (int)prev;
    }
};