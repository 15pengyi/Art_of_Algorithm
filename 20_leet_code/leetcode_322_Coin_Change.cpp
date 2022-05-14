#include <vector>
#include <map>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        sort(coins.begin(), coins.end());
        vector<int> dp(amount + 1, numeric_limits<int>::max() - 1);
        dp[0] = 0;
        for (auto one : coins)
        {
            if (one > amount)
            {
                break;
            }
            dp[one] = 1;
            for (int i = one + 1; i <= amount; ++i)
            {
                dp[i] = min(dp[i], dp[i - one] + 1);
            }
        }
        return dp[amount] == numeric_limits<int>::max() - 1 ? -1 : dp[amount];
    }
};