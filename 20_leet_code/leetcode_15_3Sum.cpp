#include <vector>
#include <map>
#include <string>
#include <set>
#include <tuple>
#include <limits>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> results;
        set<tuple<int, int>> resultSet;
        if (nums.empty())
        {
            return results;
        }
        sort(nums.begin(), nums.end());
        map<int, int> map1;
        for (int k = 0; k < nums.size(); ++k)
        {
            map1[nums[k]] = k;
        }
        map<int, set<int>> map2;
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                int sum2(nums[i] + nums[j]);
                if (-sum2 < nums[i] || -sum2 > nums[j])
                {
                    continue;
                }
                if (map2.count(sum2) > 0 && map2[sum2].count(nums[i]) > 0)
                {
                    continue;
                }
                if (map1.count(-sum2) == 0)
                {
                    continue;
                }
                int k(map1[-sum2]);
                if (k == i || k == j)
                {
                    continue;
                }
                map2[sum2].insert(nums[i]);
                results.push_back(vector<int>({nums[i], nums[k], nums[j]}));
            }
        }
        return results;
    }
};