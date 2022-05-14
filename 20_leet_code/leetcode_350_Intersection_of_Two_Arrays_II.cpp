#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        map<int, int> map1;
        for (const auto &n : nums1)
        {
            map1[n]++;
        }
        map<int, int> map2;
        for (const auto &n : nums2)
        {
            map2[n]++;
        }
        vector<int> res;
        for (const auto &p : map1)
        {
            int s(min(map1[p.first], map2[p.first]));
            for (int i = 0; i < s; ++i)
            {
                res.push_back(p.first);
            }
        }
        return res;
    }
};