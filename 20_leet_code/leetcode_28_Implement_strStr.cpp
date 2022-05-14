#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.empty())
            return 0;

        vector<int> next(needle.size(), 0);
        for (int i = 1, k = 0; i < needle.size(); ++i)
        {
            while (k && needle[k] != needle[i])
                k = next[k - 1];
            if (needle[k] == needle[i])
                ++k;
            next[i] = k;
        }

        for (int i = 0, k = 0; i < haystack.size(); ++i)
        {
            while (k && needle[k] != haystack[i])
                k = next[k - 1];
            if (needle[k] == haystack[i])
                ++k;
            if (k == needle.size())
                return i - k + 1;
        }

        return -1;
    }
};