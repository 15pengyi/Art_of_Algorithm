#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        map<char, int> number{
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

        int total(0), left(0);
        for (auto &c : s)
        {
            int v(number[c]);
            total += v > left ? v - left * 2 : v;
            left = v;
        }
        return total;
    }
};