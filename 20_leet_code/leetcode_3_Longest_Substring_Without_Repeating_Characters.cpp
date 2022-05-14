#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> number;
        for (auto c : s)
        {
            number.push_back((int)c);
        }
        int maxLength(0), length(0), start(0);
        vector<int> counter(256);
        for (int i = 0; i < number.size(); ++i)
        {
            ++counter[number[i]];
            ++length;
            while (counter[number[i]] > 1)
            {
                --counter[number[start++]];
                --length;
            }
            if (maxLength < length)
            {
                maxLength = length;
            }
        }
        return maxLength;
    }
};
