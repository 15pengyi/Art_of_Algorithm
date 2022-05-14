#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    string s, end("#");
    cin >> s;
    while (end.compare(s) != 0)
    {
        // next_permutation
        if (s.size() < 2)
        {
            cout << "No Successor" << endl;
        }
        else
        {
            // is_sorted_until
            int i(s.size() - 2);
            for (; i >= 0 && s[i] >= s[i + 1]; --i)
                ;
            if (i < 0)
            {
                cout << "No Successor" << endl;
            }
            else
            {
                // upper_bound + iter_swap + reverse
                char first(s[i]);
                sort(s.begin() + i, s.end());
                int j(i + 1);
                for (; j < s.size() && s[j] <= first; ++j)
                    ;
                char next(s[j]);
                for (; j > i; --j)
                    s[j] = s[j - 1];
                s[i] = next;
                cout << s << endl;
            }
        }
        cin >> s;
    }
    return 0;
}