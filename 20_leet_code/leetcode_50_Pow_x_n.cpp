#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        if (x == 0.0)
        {
            return 0.0;
        }
        if (n == 0)
        {
            return 1.0;
        }
        else if (n > 0)
        {
            double p(x);
            double ret(1.0);
            while (n > 0)
            {
                if (n & 1)
                {
                    ret *= p;
                }
                p *= p;
                n >>= 1;
            }
            return ret;
        }
        else
        {
            n = -n;
            double p(x);
            double ret(1.0);
            while (n > 0)
            {
                if (n & 1)
                {
                    ret *= p;
                }
                p *= p;
                n >>= 1;
            }
            return 1.0 / ret;
        }
    }
};