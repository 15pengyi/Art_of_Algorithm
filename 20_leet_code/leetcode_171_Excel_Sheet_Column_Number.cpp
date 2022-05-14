#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    int titleToNumber(string s)
    {
        int base = 1;
        int total = 0;
        for (int i = s.size() - 1; i >= 0; --i)
        {
            total += (s[i] - 'A' + 1) * base;
            base *= 26;
        }
        return total;
    }
};