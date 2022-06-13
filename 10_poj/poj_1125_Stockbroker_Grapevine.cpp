#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    while (n > 0)
    {
        vector<vector<int> > time(n, vector<int>(n, -1));
        for (int i = 0; i < n; ++i)
            time[i][i] = 0;
        for (int i = 0; i < n; ++i)
        {
            int contacts;
            cin >> contacts;
            for (int j = 0; j < contacts; ++j)
            {
                int c, t;
                cin >> c >> t;
                time[i][c - 1] = t;
            }
        }
        int final_person(0), final_time(-1);
        for (int person = 0; person < n; ++person)
        {
            vector<int> min_time(n, -1);
            vector<bool> visit(n, false);
            for (int i = 0; i < n; ++i)
                min_time[i] = time[person][i];
            visit[person] = true;
            for (int k = 1; k < n; ++k)
            {
                int min_person(person), min(-1);
                for (int i = 0; i < n; ++i)
                {
                    if (!visit[i] && min_time[i] != -1 && (min == -1 || min_time[i] < min))
                    {
                        min = min_time[i];
                        min_person = i;
                    }
                }
                visit[min_person] = true;
                for (int i = 0; i < n; ++i)
                {
                    if (!visit[i] && time[min_person][i] != -1 && (min_time[i] == -1 || min_time[min_person] + time[min_person][i] < min_time[i]))
                    {
                        min_time[i] = min_time[min_person] + time[min_person][i];
                    }
                }
            }
            int max_min_time(-1);
            for (int i = 0; i < n; ++i)
            {
                if (min_time[i] == -1)
                {
                    max_min_time = -1;
                    break;
                }
                if (max_min_time == -1 || min_time[i] > max_min_time)
                    max_min_time = min_time[i];
            }
            if (max_min_time != -1 && (final_time == -1 || max_min_time < final_time))
            {
                final_person = person;
                final_time = max_min_time;
            }
        }
        if (final_time == -1)
            cout << "disjoint" << endl;
        else
            cout << final_person + 1 << " " << final_time << endl;
        cin >> n;
    }
    return 0;
}