#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    int longestSubstring(string s, int k)
    {
        map<char, int> m;
        for (const auto &c : s)
            m[c]++;

        string d;
        for (const auto &p : m)
            if (p.second < k)
                d.push_back(p.first);
        if (d.empty())
            return s.size();

        int l(0);
        for (const auto &t : split(s, d))
            l = max(l, longestSubstring(t, k));
        return l;
    }

    vector<string> split(const string &s, const string &d)
    {
        vector<string> v(0);
        int l(0);
        for (int r = 0; (r = s.find_first_of(d, l)) != string::npos; l = r + 1)
        {
            if (l < r)
            {
                v.push_back(s.substr(l, r - l));
            }
        }
        if (l < s.size())
        {
            v.push_back(s.substr(l));
        }
        return v;
    }
};