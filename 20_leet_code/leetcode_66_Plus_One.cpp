#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        if (digits.size() == 0)
        {
            return digits;
        }

        int position = digits.size() - 1;
        while (position >= 0 && digits[position] == 9)
        {
            digits[position--] = 0;
        }
        if (position >= 0)
        {
            digits[position]++;
        }
        else
        {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};