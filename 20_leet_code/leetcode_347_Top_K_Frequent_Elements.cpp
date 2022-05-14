#include <vector>
#include <map>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

class Solution
{
public:
    static bool compare(pair<int, int> i, pair<int, int> j)
    {
        return i.second > j.second;
    }

    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        if (nums.empty())
        {
            return vector<int>();
        }
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> pairs(1, pair<int, int>(nums.front(), 1));
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] != nums[i - 1])
            {
                pairs.push_back(pair<int, int>(nums[i], 1));
            }
            else
            {
                pairs.back().second += 1;
            }
        }
        sort(pairs.begin(), pairs.end(), compare);
        vector<int> res(0);
        int size(min(k, (int)pairs.size()));
        for (int i = 0; i < size; ++i)
        {
            res.push_back(pairs[i].first);
        }
        return res;
    }
};