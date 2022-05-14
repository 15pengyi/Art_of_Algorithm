#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {

        int rows = matrix.size();
        if (rows == 0)
        {
            return;
        }

        int cols = matrix.front().size();
        if (cols == 0)
        {
            return;
        }

        bool clearAll = matrix[0][0] == 0;
        bool clearCol = clearAll;
        if (!clearCol)
        {
            for (int r = 1; r < rows && !clearCol; ++r)
            {
                clearCol = matrix[r][0] == 0;
            }
        }
        bool clearRow = clearAll;
        if (!clearRow)
        {
            for (int c = 1; c < cols && !clearRow; ++c)
            {
                clearRow = matrix[0][c] == 0;
            }
        }

        for (int r = 1; r < rows; ++r)
        {
            for (int c = 1; c < cols && matrix[r][0]; ++c)
            {
                if (!matrix[r][c])
                {
                    matrix[r][0] = 0;
                }
            }
        }
        for (int c = 1; c < cols; ++c)
        {
            for (int r = 1; r < rows && matrix[0][c]; ++r)
            {
                if (!matrix[r][c])
                {
                    matrix[0][c] = 0;
                }
            }
        }

        for (int r = 1; r < rows; ++r)
        {
            for (int c = 1; c < cols; ++c)
            {
                if (!matrix[r][0] || !matrix[0][c])
                {
                    matrix[r][c] = 0;
                }
            }
        }

        if (clearAll || clearCol)
        {
            for (int r = 0; r < rows; ++r)
            {
                matrix[r][0] = 0;
            }
        }

        if (clearAll || clearRow)
        {
            for (int c = 0; c < cols; ++c)
            {
                matrix[0][c] = 0;
            }
        }
    }
};