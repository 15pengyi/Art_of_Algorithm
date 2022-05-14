#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }
        int maxProd(numeric_limits<int>::min()), minProd(numeric_limits<int>::max());
        for (const auto &n : nums)
        {
            maxProd = max(maxProd, n);
            minProd = min(minProd, n);
        }
        int maxProdCur(nums.front()), minProdCur(nums.front());
        for (int i = 1; i < nums.size(); ++i)
        {
            int num(nums[i]);
            int maxCur = max(max(num, maxProdCur * num), minProdCur * num);
            int minCur = min(min(num, minProdCur * num), maxProdCur * num);
            maxProdCur = maxCur;
            minProdCur = minCur;
            maxProd = max(maxProd, maxProdCur);
            minProd = min(minProd, minProdCur);
        }
        return maxProd;
    }
};