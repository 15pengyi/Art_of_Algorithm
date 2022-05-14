#include <vector>
#include <map>
#include <string>
#include <set>
#include <limits>

using namespace std;

class Solution
{
public:
    bool exist(string s, vector<string> &wordDict)
    {
        set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> segment(s.size(), false);
        for (int i = 0; i < s.size(); ++i)
        {
            if (wordSet.find(s.substr(0, i + 1)) != wordSet.end())
            {
                segment[i] = true;
            }
            else
            {
                for (int j = 1; j <= i && !segment[i]; ++j)
                {
                    if (wordSet.find(s.substr(j, i - j + 1)) != wordSet.end())
                    {
                        segment[i] = segment[j - 1];
                    }
                }
            }
        }
        return segment[s.size() - 1];
    }

    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        if (!exist(s, wordDict))
        {
            return vector<string>();
        }
        set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<vector<string>> segment(s.size());
        for (int i = 0; i < s.size(); ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                string word(s.substr(j, i - j + 1));
                if (wordSet.find(word) != wordSet.end())
                {
                    if (j == 0)
                    {
                        segment[i].push_back(word);
                    }
                    else
                    {
                        for (const auto &seg : segment[j - 1])
                        {
                            segment[i].push_back(seg + " " + word);
                        }
                    }
                }
            }
        }
        return segment[s.size() - 1];
    }
};