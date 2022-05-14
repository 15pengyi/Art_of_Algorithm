#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        vector<int> value(gas.size());
        for (int i = 0; i < gas.size(); ++i)
        {
            value[i] = gas[i] - cost[i];
        }
        int total(0);
        int curValue(0);
        int curIndex(0);
        for (int i = 0; i < value.size(); ++i)
        {
            curValue += value[i];
            total += value[i];
            if (curValue < 0)
            {
                curValue = 0;
                curIndex = i + 1;
            }
        }
        return total < 0 || curIndex == value.size() ? -1 : curIndex;
    }
};