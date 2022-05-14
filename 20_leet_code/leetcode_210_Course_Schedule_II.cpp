#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites)
    {
        vector<vector<int>> outs(numCourses);
        for (const auto &p : prerequisites)
        {
            outs[p.first].push_back(p.second);
        }

        vector<int> in(numCourses, 0);
        for (const auto &p : prerequisites)
        {
            in[p.second]++;
        }

        vector<int> zeros;
        for (int i = 0; i < numCourses; ++i)
        {
            if (in[i] == 0)
            {
                zeros.push_back(i);
            }
        }

        vector<int> res;
        vector<bool> visit(numCourses, false);
        while (res.size() < numCourses)
        {
            if (zeros.empty())
            {
                return vector<int>();
            }
            int z(zeros.back());
            zeros.pop_back();
            res.push_back(z);
            for (const auto &o : outs[z])
            {
                if (--in[o] == 0)
                {
                    zeros.push_back(o);
                }
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};