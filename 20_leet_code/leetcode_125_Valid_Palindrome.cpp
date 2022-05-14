#include <vector>
#include <map>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        s.erase(remove_if(s.begin(), s.end(),
                          [](char x)
                          { return !(
                                (x >= 'a' && x <= 'z') ||
                                (x >= 'A' && x <= 'Z') ||
                                (x >= '0' && x <= '9')); }),
                s.end());
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        // cout << s << endl;
        if (s.empty())
        {
            return true;
        }
        for (auto l(s.begin()), r(s.end() - 1); l < r; ++l, --r)
        {
            if (*l != *r)
                return false;
        }
        return true;
    }
};