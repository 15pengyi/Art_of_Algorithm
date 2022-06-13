#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    vector<int> dr(4), dc(4);
    dr[0] = 0;
    dc[0] = 1;
    dr[1] = 0;
    dc[1] = -1;
    dr[2] = -1;
    dc[2] = 0;
    dr[3] = 1;
    dc[3] = 0;

    int t(0);
    cin >> t;
    for (; t > 0; --t)
    {
        int m(0), n(0);
        cin >> m >> n;
        vector<vector<bool>> obstacle(m, vector<bool>(n, false));
        vector<vector<bool>> available(m, vector<bool>(n, false));
        for (int r = 0; r < m; ++r)
        {
            for (int c = 0; c < n; ++c)
            {
                int o(0);
                cin >> o;
                obstacle[r][c] = (o == 1);
                available[r][c] = (o == 0);
            }
        }
        vector<vector<int>> trips;
        int min(0), max(0);
        cin >> min >> max;
        while (min > 0 && max > 0)
        {
            vector<int> trip(3, 0);
            char dir(0);
            cin >> dir;
            switch (dir)
            {
            case 'R':
                trip[0] = 1;
                break;
            case 'L':
                trip[0] = 0;
                break;
            case 'U':
                trip[0] = 3;
                break;
            case 'D':
                trip[0] = 2;
                break;
            default:
                break;
            }
            trip[1] = min;
            trip[2] = max;
            trips.push_back(trip);

            cin >> min >> max;
        }

        for (int l = trips.size() - 1; l >= 0; --l)
        {
            vector<int> trip = trips[l];
            int dir(trip[0]);

            vector<vector<bool>> from(m, vector<bool>(n, false));
            for (int r = 0; r < m; ++r)
            {
                for (int c = 0; c < n; ++c)
                {
                    if (!available[r][c])
                        continue;
                    for (int len = 1; len <= trip[2]; ++len)
                    {
                        int rt(r + dr[dir] * len), ct(c + dc[dir] * len);
                        if (rt < 0 || rt >= m || ct < 0 || ct >= n)
                            break;
                        if (obstacle[rt][ct])
                            break;
                        if (len >= trip[1])
                            from[rt][ct] = true;
                    }
                }
            }

            available = from;
        }

        int num(0);
        for (int r = 0; r < m; ++r)
        {
            for (int c = 0; c < n; ++c)
            {
                if (available[r][c])
                    ++num;
            }
        }
        cout << num << endl;
    }

    return 0;
}