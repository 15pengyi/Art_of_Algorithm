#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <limits>

using namespace std;

class Solution
{
public:
    vector<int> nums;
    int size;

    void solve(int n)
    {
        if (n == 0)
        {
            size = nums.size();
        }
        else if (size > nums.size())
        {
            int back(nums.empty() ? n : nums.back());
            nums.push_back(0);
            for (int t = min((int)sqrt(n), back); t >= max((int)sqrt(n / (size - nums.size() + 1)), 1); --t)
            {
                nums.back() = t;
                solve(n - t * t);
                nums.back() = 0;
            }
            nums.pop_back();
        }
    }

    int numSquares(int n)
    {
        size = n;
        solve(n);
        return size;
    }
};