#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

vector<int> add(int size, vector<int> &x, vector<int> &y)
{
    vector<int> result(size, 0);
    if (x.size() != size)
        return result;
    if (y.size() != size)
        return result;
    for (int i = 0; i < size; ++i)
    {
        int r(result[i] + x[i] + y[i]);
        result[i] = r % 10;
        if (i + 1 < size)
            result[i + 1] = r / 10;
    }
    return result;
}

vector<int> multiply(int size, vector<int> &x, int y)
{
    vector<int> result(size, 0);
    if (x.size() != size)
        return result;
    for (int i = 0; i < size; ++i)
    {
        int r(result[i] + x[i] * y);
        result[i] = r % 10;
        if (i + 1 < size)
            result[i + 1] = r / 10;
    }
    return result;
}

int main(int argc, char *argv[])
{
    string octal;
    while (cin >> octal)
    {
        int size(octal.size() - 2);
        vector<int> result(size * 3);
        for (int i = 0; i < size; ++i)
        {
            vector<int> x(size * 3);
            x[i * 3] = (int)octal[octal.size() - 1 - i] - (int)'0';
            result = add(size * 3, result, x);
            result = multiply(size * 3, result, 125);
        }
        cout << octal << " [8] = 0.";
        for (int i = size * 3 - 1; i >= 0; --i)
            cout << result[i];
        cout << " [10]" << endl;
    }
    return 0;
}