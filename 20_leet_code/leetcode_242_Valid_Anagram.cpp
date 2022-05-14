#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        vector<int> countS(26), countT(26);
        for (const auto &c : s)
        {
            countS[c - 'a']++;
        }
        for (const auto &c : t)
        {
            countT[c - 'a']++;
        }
        for (int i = 0; i < 26; ++i)
        {
            if (countS[i] != countT[i])
                return false;
        }
        return true;
    }
};