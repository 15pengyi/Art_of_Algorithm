#include <vector>
#include <map>
#include <string>
#include <set>
#include <limits>

using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> segment(s.size(), false);
        for (int i = 0; i < s.size(); ++i)
        {
            for (int j = 0; j <= i && !segment[i]; ++j)
            {
                if (wordSet.find(s.substr(j, i - j + 1)) != wordSet.end())
                {
                    segment[i] = j == 0 || segment[j - 1];
                }
            }
        }
        return !s.empty() && segment[s.size() - 1];
    }
};