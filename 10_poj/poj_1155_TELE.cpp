#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

vector<int> solve(int n, int m,
                  const vector<vector<int> > &children,
                  const vector<int> &cost,
                  const vector<int> &price,
                  int number)
{
    vector<int> result;
    if (number >= n - m)
    {
        int index(number - (n - m));
        result.assign(1, price[index] - cost[number]);
    }
    else
    {
        const vector<int> &child = children[number];
        result = solve(n, m, children, cost, price, child[0]);
        for (int i = 1; i < child.size(); ++i)
        {
            vector<int> r1 = result;
            vector<int> r2 = solve(n, m, children, cost, price, child[i]);
            result.assign(r1.size() + r2.size(), numeric_limits<int>::min());
            for (int j = 0; j < r1.size(); ++j)
                result[j] = max(result[j], r1[j]);
            for (int k = 0; k < r2.size(); ++k)
                result[k] = max(result[k], r2[k]);
            for (int j = 0; j < r1.size(); ++j)
                for (int k = 0; k < r2.size(); ++k)
                    result[j + k + 1] = max(result[j + k + 1], r1[j] + r2[k]);
        }
        for (int i = 0; i < result.size(); ++i)
            result[i] -= cost[number];
    }
    return result;
}

int main(int argc, char *argv[])
{
    int n, m;
    cin >> n >> m;
    int transmitters(n - m);
    vector<vector<int> > children(transmitters);
    vector<int> cost(n, 0);
    for (int i = 0; i < transmitters; ++i)
    {
        int size;
        cin >> size;
        children[i].resize(size);
        for (int j = 0; j < size; ++j)
        {
            cin >> children[i][j];
            cin >> cost[--children[i][j]];
        }
    }
    vector<int> price(m, 0);
    for (int i = 0; i < m; ++i)
    {
        cin >> price[i];
    }
    int num = -1;
    vector<int> result = solve(n, m, children, cost, price, 0);
    for (int i = 0; i < result.size(); ++i)
        if (result[i] >= 0)
            num = max(num, i);
    cout << (num + 1) << endl;
    return 0;
}