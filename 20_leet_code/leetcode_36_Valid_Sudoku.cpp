#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        std::vector<std::vector<bool>> rowFilled(9, std::vector<bool>(9, false));
        std::vector<std::vector<bool>> colFilled(9, std::vector<bool>(9, false));
        std::vector<std::vector<bool>> grdFilled(9, std::vector<bool>(9, false));
        for (int gy = 0; gy < 3; ++gy)
        {
            for (int gx = 0; gx < 3; ++gx)
            {
                for (int y = 0; y < 3; ++y)
                {
                    for (int x = 0; x < 3; ++x)
                    {
                        int r = gy * 3 + y;
                        int c = gx * 3 + x;
                        int g = gy * 3 + gx;
                        int v = board[r][c] == '.' ? -1 : board[r][c] - '1';
                        if (v >= 0)
                        {
                            if (grdFilled[g][v])
                            {
                                return false;
                            }
                            grdFilled[g][v] = true;

                            if (rowFilled[r][v])
                            {
                                return false;
                            }
                            rowFilled[r][v] = true;

                            if (colFilled[c][v])
                            {
                                return false;
                            }
                            colFilled[c][v] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
};