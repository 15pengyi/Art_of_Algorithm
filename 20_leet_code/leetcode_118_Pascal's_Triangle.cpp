#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        if (numRows == 0)
        {
            return std::vector<std::vector<int>>();
        }

        std::vector<std::vector<int>> ret(1, std::vector<int>(1, 1));
        for (int i = 1; i < numRows; ++i)
        {
            std::vector<int> row(i + 1, 1);
            for (int j = 1; j < i; ++j)
            {
                row[j] = ret[i - 1][j - 1] + ret[i - 1][j];
            }
            ret.push_back(row);
        }
        return ret;
    }
};