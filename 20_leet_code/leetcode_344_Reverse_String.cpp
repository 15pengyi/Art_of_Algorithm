#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    string reverseString(string s)
    {
        int half_size(s.size() / 2);
        for (int i = 0; i < half_size; ++i)
        {
            int j(s.size() - 1 - i);
            char c(s[i]);
            s[i] = s[j];
            s[j] = c;
        }
        return s;
    }
};