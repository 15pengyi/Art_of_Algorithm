#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n(nums.size());
        int prodBegin(1);
        int prodLast(1);
        vector<int> res(n, 1);
        for (int i = 0; i < n; i++)
        {
            res[i] *= prodBegin;
            prodBegin *= nums[i];
            res[n - 1 - i] *= prodLast;
            prodLast *= nums[n - 1 - i];
        }
        return res;
    }
};