#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        map<int, int> cha;
        vector<map<int, int>> pos('z' - 'A' + 1);
        for (int i = 0; i < t.size(); ++i)
        {
            int c(t[i] - 'A');
            pos[c].insert({-1 - i, i});
            cha.insert({-1 - i, i});
        }

        string res;
        for (int i = 0; i < s.size(); ++i)
        {
            int c(s[i] - 'A');
            map<int, int> &m(pos[c]);
            if (!m.empty())
            {
                int f(m.begin()->first);
                int p(m.begin()->second);
                m.erase(f);
                m.insert({i, p});
                cha.erase(f);
                cha.insert({i, p});
                int first(cha.begin()->first);
                if (first >= 0)
                {
                    if (res.empty() || (i - first + 1) < res.size())
                    {
                        res = s.substr(first, i - first + 1);
                    }
                }
                // cout << "i: " << i << endl;
                // cout << "p: " << p << endl;
                // cout << "size: " << size[i] << endl;
            }
        }
        return res;
    }
};