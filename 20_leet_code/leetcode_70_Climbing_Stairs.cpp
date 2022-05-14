#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n < 2)
        {
            return 1;
        }
        else
        {
            int a = 1;
            int b = 1;
            for (int i = 1; i < n; i++)
            {
                int c = a + b;
                a = b;
                b = c;
            }
            return b;
        }
    }
};