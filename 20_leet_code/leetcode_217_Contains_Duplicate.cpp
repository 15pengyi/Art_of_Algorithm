#include <vector>
#include <map>
#include <string>
#include <set>
#include <limits>

using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        set<int> s;
        for (const auto &n : nums)
        {
            if (s.find(n) != s.end())
                return true;
            s.insert(n);
        }
        return false;
    }
};