#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<string, vector<string>> m;
        for (const auto &str : strs)
        {
            vector<int> count(26, 0);
            for (const auto &c : str)
            {
                count[c - 'a']++;
            }
            string key;
            for (int i = 0; i < 26; ++i)
            {
                if (count[i] > 0)
                {
                    key += ('a' + i);
                    key += to_string(count[i]);
                }
            }
            m[key].push_back(str);
        }
        vector<vector<string>> res;
        for (const auto &p : m)
        {
            res.push_back(p.second);
        }
        return res;
    }
};