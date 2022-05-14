#include <vector>
#include <map>
#include <string>
#include <set>
#include <limits>

using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        std::set<int> visited;
        while (true)
        {
            if (n == 1 || visited.count(n) > 0)
            {
                break;
            }
            visited.insert(n);
            int sum = 0;
            int m = n;
            while (m > 0)
            {
                int digit = m % 10;
                m = m / 10;
                sum += digit * digit;
            }
            n = sum;
        }
        return n == 1;
    }
};