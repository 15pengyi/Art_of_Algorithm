#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    int v(0), p(0);
    cin >> v >> p;
    vector<int> positions(v, 0);
    for (int i = 0; i < v; ++i)
        cin >> positions[i];
    positions.push_back(numeric_limits<int>::max());
    ++v;
    ++p;

    vector<vector<int> > distances(v - 1, vector<int>(v, 0));
    for (int i = 0; i < v; ++i)
        for (int j = i + 1; j < v; ++j)
        {
            int distance(0);
            for (int k = i; k <= j; ++k)
                distance += min(positions[k] - positions[i], positions[j] - positions[k]);
            distances[i][j] = distance;
        }
    vector<vector<int> > cost(p, vector<int>(v, 0));
    int i = 0;
    int j = 0;
    cost[i][j] = 0;
    for (++j; j < v; ++j)
    {
        int distance(0);
        for (int k = 0; k <= j; ++k)
            distance += positions[j] - positions[k];
        cost[i][j] = distance;
    }
    for (++i; i < p; ++i)
    {
        for (j = i; j < v; ++j)
        {
            int k = 1;
            cost[i][j] = cost[i - 1][k] + distances[k][j];
            for (++k; k < j; ++k)
                cost[i][j] = min(cost[i][j], cost[i - 1][k] + distances[k][j]);
        }
    }
    cout << cost[p - 1][v - 1] << endl;
    return 0;
}