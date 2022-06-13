#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    vector<pair<int, int> > delta;
    delta.push_back(pair<int, int>(0, 1));
    delta.push_back(pair<int, int>(1, 0));
    delta.push_back(pair<int, int>(0, -1));
    delta.push_back(pair<int, int>(-1, 0));
    vector<int> mask;
    mask.push_back(4);
    mask.push_back(8);
    mask.push_back(1);
    mask.push_back(2);

    int m, n;
    cin >> m >> n;
    vector<vector<int> > number(m, vector<int>(n, 0));
    vector<vector<bool> > visit(m, vector<bool>(n, false));
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> number[i][j];
        }
    }
    int rooms(0), max_area(0);
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (visit[i][j])
                continue;

            ++rooms;
            int area(1);
            vector<pair<int, int> > queue(1, pair<int, int>(i, j));
            visit[i][j] = true;
            while (!queue.empty())
            {
                pair<int, int> cur(queue.back());
                queue.pop_back();
                int r(cur.first), c(cur.second);
                for (int i = 0; i < 4; ++i)
                {
                    if (number[r][c] & mask[i])
                        continue;

                    int rn(r + delta[i].first);
                    int cn(c + delta[i].second);
                    if (rn >= 0 && rn < m && cn >= 0 && cn < n && !visit[rn][cn])
                    {
                        visit[rn][cn] = true;
                        queue.push_back(pair<int, int>(rn, cn));
                        ++area;
                    }
                }
            }
            max_area = max(max_area, area);
        }
    }
    cout << rooms << endl;
    cout << max_area << endl;
    return 0;
}