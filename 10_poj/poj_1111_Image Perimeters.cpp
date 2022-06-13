#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    vector<pair<int, int> > delta;
    delta.push_back(pair<int, int>(0, 1));
    delta.push_back(pair<int, int>(1, 0));
    delta.push_back(pair<int, int>(0, -1));
    delta.push_back(pair<int, int>(-1, 0));
    delta.push_back(pair<int, int>(1, 1));
    delta.push_back(pair<int, int>(-1, 1));
    delta.push_back(pair<int, int>(-1, -1));
    delta.push_back(pair<int, int>(1, -1));

    int rows, columns, r, c;
    cin >> rows >> columns >> r >> c;
    while (rows > 0 && columns > 0 && r > 0 && c > 0)
    {
        vector<vector<bool> > map(rows, vector<bool>(columns, false));
        for (int i = 0; i < rows; ++i)
        {
            string s;
            cin >> s;
            for (int j = 0; j < columns; ++j)
                map[i][j] = (s[j] == 'X');
        }

        int perimeter(0);
        vector<vector<bool> > visit(rows, vector<bool>(columns, false));
        vector<pair<int, int> > queue;
        if (map[--r][--c])
        {
            visit[r][c] = true;
            queue.push_back(pair<int, int>(r, c));
            perimeter += 4;
            for (int i = 0; i < 4; ++i)
            {
                int rn(r + delta[i].first);
                int cn(c + delta[i].second);
                if (rn >= 0 && rn < rows && cn >= 0 && cn < columns && visit[rn][cn])
                    perimeter -= 2;
            }
        }
        while (!queue.empty())
        {
            pair<int, int> cur(queue.back());
            queue.pop_back();
            int r(cur.first), c(cur.second);
            for (int i = 0; i < 8; ++i)
            {
                int rn(r + delta[i].first);
                int cn(c + delta[i].second);
                if (rn >= 0 && rn < rows && cn >= 0 && cn < columns && map[rn][cn] && !visit[rn][cn])
                {
                    visit[rn][cn] = true;
                    queue.push_back(pair<int, int>(rn, cn));
                    perimeter += 4;
                    for (int j = 0; j < 4; ++j)
                    {
                        int rnn(rn + delta[j].first);
                        int cnn(cn + delta[j].second);
                        if (rnn >= 0 && rnn < rows && cnn >= 0 && cnn < columns && visit[rnn][cnn])
                            perimeter -= 2;
                    }
                }
            }
        }
        cout << perimeter << endl;

        cin >> rows >> columns >> r >> c;
    }
    return 0;
}