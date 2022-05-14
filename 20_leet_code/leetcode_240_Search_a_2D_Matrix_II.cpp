#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    bool searchMatrix(const vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty())
        {
            return 0;
        }
        int m = matrix.size();
        int n = matrix.front().size();
        int i = m - 1, j = 0;
        while (i >= 0 && j < n)
        {
            if (matrix[i][j] == target)
            {
                return true;
            }
            else if (matrix[i][j] < target)
            {
                j++;
            }
            else
            {
                i--;
            }
        }
        return false;
    }
};