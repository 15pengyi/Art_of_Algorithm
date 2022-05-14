#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        if (matrix.empty())
        {
            return {};
        }
        vector<pair<int, int>> directions({{0, 1}, {1, 0}, {-1, 0}, {0, -1}});
        int rows(matrix.size());
        int cols(matrix.front().size());
        vector<int> visit(rows * cols, false);
        vector<int> res(0);
        int dir(0), row(0), col(0);
        visit[0] = true;
        res.push_back(matrix[row][col]);
        for (int i = rows * cols - 1; i > 0; --i)
        {
            for (int j = 0; j < 4; ++j)
            {
                int d((dir + j) % 4);
                int r(row + directions[d].first);
                int c(col + directions[d].second);
                int index(r * cols + c);
                if (r >= 0 && r < rows && c >= 0 && c < cols &&
                    !visit[index])
                {
                    visit[index] = true;
                    row = r;
                    col = c;
                    dir = d;
                    res.push_back(matrix[row][col]);
                    break;
                }
            }
        }
        return res;
    }
};