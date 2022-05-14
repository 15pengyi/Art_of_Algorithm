#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        vector<int> count(26, 0);
        for (const auto &c : s)
        {
            ++count[c - 'a'];
        }
        for (int i = 0; i < s.size(); ++i)
        {
            if (count[s[i] - 'a'] < 2)
                return i;
        }
        return -1;
    }
};