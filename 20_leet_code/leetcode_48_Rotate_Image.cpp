#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix.front().size();
        std::vector<std::vector<int>> matrixRotated(cols);
        for (auto &m : matrixRotated)
        {
            m.resize(rows);
        }
        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c)
            {
                matrixRotated[c][rows - 1 - r] = matrix[r][c];
            }
        }
        matrix = matrixRotated;
    }
};