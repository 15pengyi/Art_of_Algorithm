#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        --m, --n;
        m = m + n;
        if (n > m / 2)
        {
            n = m - n;
        }
        long long ret = 1;
        for (int i = n + 1; i <= m; i++)
        {
            ret = ret * i / (i - n);
        }
        return ret;
    }
};