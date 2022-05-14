#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxValue = std::numeric_limits<int>::lowest();
        int current = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            current += prices[i] - prices[i - 1];
            maxValue = std::max<int>(maxValue, current);
            if (current < 0)
            {
                current = 0;
            }
        }
        return maxValue > 0 ? maxValue : 0;
    }
};