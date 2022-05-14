#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string result;
        if (strs.empty())
        {
            return result;
        }
        int size(0);
        int minSize(strs.front().size());
        for (const auto &s : strs)
        {
            minSize = min<int>(minSize, s.size());
        }
        while (size < minSize)
        {
            bool match(true);
            char c(strs.front()[size]);
            for (const auto &s : strs)
            {
                if (!(match = s[size] == c))
                {
                    break;
                }
            }
            if (!match)
            {
                break;
            }
            result += c;
            ++size;
        }
        return result;
    }
};