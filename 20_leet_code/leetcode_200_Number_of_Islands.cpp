#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.empty())
        {
            return 0;
        }

        int count(0);
        int rows(grid.size());
        int columns(grid.front().size());
        vector<vector<int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        vector<vector<bool>> visit(rows);
        for (auto &r : visit)
        {
            r.resize(columns, false);
        }
        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < columns; ++c)
            {
                if (grid[r][c] == '0' || visit[r][c])
                {
                    continue;
                }

                vector<int> queue;
                queue.push_back(r * columns + c);
                visit[r][c] = true;

                while (!queue.empty())
                {
                    int index(queue.back());
                    queue.pop_back();

                    int r1(index / columns);
                    int c1(index % columns);
                    for (const auto &d : directions)
                    {
                        int r2(r1 + d[0]);
                        int c2(c1 + d[1]);
                        if (r2 >= 0 && r2 < rows && c2 >= 0 && c2 < columns &&
                            grid[r2][c2] == '1' && !visit[r2][c2])
                        {
                            queue.push_back(r2 * columns + c2);
                            visit[r2][c2] = true;
                        }
                    }
                }
                count++;
            }
        }
        return count;
    }
};