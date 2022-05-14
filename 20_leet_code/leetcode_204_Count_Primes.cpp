#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    int countPrimes(int n)
    {
        int count(0);
        vector<bool> sieve(n, true);
        sieve[0] = sieve[1] = false;
        for (int i = 2; i < n; ++i)
        {
            if (sieve[i])
            {
                ++count;
                for (int j = i; j < n; j += i)
                {
                    sieve[j] = false;
                }
            }
        }
        return count;
    }
};