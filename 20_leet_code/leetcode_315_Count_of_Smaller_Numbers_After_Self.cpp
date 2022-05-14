#include <vector>
#include <map>
#include <string>
#include <numeric>
#include <limits>

using namespace std;

class Solution
{
protected:
    void merge(vector<int> &indices, int first, int last,
               vector<int> &results, vector<int> &nums)
    {
        if (last - first > 1)
        {
            int mid = first + (last - first) / 2;
            merge(indices, first, mid, results, nums);
            merge(indices, mid, last, results, nums);
            vector<int> tmp;
            int i(first), j(mid), inv(0);
            while (i < mid || j < last)
            {
                if (j == last || (i < mid && nums[indices[i]] <= nums[indices[j]]))
                {
                    tmp.push_back(indices[i]);
                    results[indices[i]] += inv;
                    ++i;
                }
                else
                {
                    tmp.push_back(indices[j]);
                    ++inv;
                    ++j;
                }
            }
            move(tmp.begin(), tmp.end(), indices.begin() + first);
        }
    }

public:
    vector<int> countSmaller(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> results(n, 0);
        vector<int> indices(n, 0);
        iota(indices.begin(), indices.end(), 0);
        merge(indices, 0, n, results, nums);
        return results;
    }
};