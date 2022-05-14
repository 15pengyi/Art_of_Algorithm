#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == numeric_limits<int>::min() && divisor == -1)
        {
            return numeric_limits<int>::max();
        }
        long dvd(abs(dividend)), dvs(abs(divisor)), ans(0);
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        while (dvd >= dvs)
        {
            long t = dvs, m = 1;
            while (t << 1 <= dvd)
            {
                t <<= 1;
                m <<= 1;
            }
            dvd -= t;
            ans += m;
        }
        return sign * ans;
    }
};