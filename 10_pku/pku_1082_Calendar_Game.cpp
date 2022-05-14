#include <iostream>
#include <vector>

using namespace std;

bool is_leap(int year)
{
    return (((year % 4 == 0) &&
             (year % 100 != 0)) ||
            (year % 400 == 0));
}

bool is_valid_date(vector<int> x)
{
    int m(x[1]);
    if (m < 1 || m > 12)
        return false;

    int d(x[2]);
    if (d < 1 || d > 31)
        return false;

    if (m == 2)
    {
        int y(x[0]);
        if (is_leap(y))
            return (d <= 29);
        else
            return (d <= 28);
    }

    if (m == 4 || m == 6 ||
        m == 9 || m == 11)
        return (d <= 30);

    return true;
}

bool is_less(vector<int> x, vector<int> y)
{
    if (x[0] != y[0])
        return x[0] < y[0];
    if (x[1] != y[1])
        return x[1] < y[1];
    return x[2] < y[2];
}

int date_to_index(vector<int> x)
{
    return (x[0] - 1900) * (31 * 12) + (x[1] - 1) * 31 + (x[2] - 1);
}

vector<int> index_to_date(int i)
{
    int y = i / (31 * 12);
    i -= y * (31 * 12);

    int m = i / 31;
    i -= m * 31;

    int d = i;

    vector<int> x(3);
    x[0] = y + 1900;
    x[1] = m + 1;
    x[2] = d + 1;
    return x;
}

vector<int> next_month(vector<int> x)
{
    if (x[1] < 12)
    {
        x[1] += 1;
    }
    else
    {
        x[1] += 1 - 12;
        x[0] += 1;
    }
    return x;
}

int main(int argc, char *argv[])
{
    vector<int> date_max(3);
    date_max[0] = 2001;
    date_max[1] = 11;
    date_max[2] = 4;
    int size((2001 - 1900 + 1) * 31 * 12);
    bool win_next_d(false);
    vector<bool> win(size, false);
    for (int i = size - 1; i >= 0; --i)
    {
        vector<int> date = index_to_date(i);
        if (!is_valid_date(date) || !is_less(date, date_max))
            continue;
        vector<int> date_next_m(next_month(date));
        if (date_next_m == date_max)
        {
            win_next_d = win[i] = true;
            continue;
        }
        if (!is_valid_date(date_next_m) || !is_less(date_next_m, date_max))
        {
            win_next_d = win[i] = !win_next_d;
            continue;
        }
        int index = date_to_index(date_next_m);
        bool win_next_m(win[index]);
        win_next_d = win[i] = !win_next_d || !win_next_m;
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        vector<int> date(3);
        cin >> date[0] >> date[1] >> date[2];
        if (win[date_to_index(date)])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}