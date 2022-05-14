#include <vector>
#include <map>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

class Solution
{
public:
    static bool compare(pair<int, int> i, pair<int, int> j)
    {
        return i.second < j.second;
    }

    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        if (matrix.empty())
        {
            return 0;
        }
        int m(matrix.size());
        int n(matrix.front().size());
        vector<pair<int, int>> nums;
        for (int r = 0; r < m; ++r)
        {
            for (int c = 0; c < n; ++c)
            {
                nums.push_back(make_pair(r * n + c, matrix[r][c]));
            }
        }
        sort(nums.begin(), nums.end(), compare);

        int maxLength(1);
        vector<vector<int>> length(m);
        for (auto &r : length)
        {
            r.resize(n, 1);
        }

        vector<pair<int, int>> dt{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for (const auto &p : nums)
        {
            int r(p.first / n);
            int c(p.first % n);
            for (int t = 0; t < 4; ++t)
            {
                int rr(r + dt[t].first);
                int cc(c + dt[t].second);
                if (rr >= 0 && rr < m && cc >= 0 && cc < n &&
                    matrix[rr][cc] < matrix[r][c])
                {
                    length[r][c] = max(length[r][c], length[rr][cc] + 1);
                }
            }
            maxLength = max(maxLength, length[r][c]);
        }
        return maxLength;
    }
};