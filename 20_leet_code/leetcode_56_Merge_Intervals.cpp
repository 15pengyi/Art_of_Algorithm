#include <vector>
#include <map>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution
{
public:
    vector<Interval> merge(vector<Interval> &ins)
    {
        if (ins.empty())
        {
            return vector<Interval>{};
        }
        sort(ins.begin(), ins.end(), [](Interval a, Interval b)
             { return a.start < b.start; });

        vector<Interval> res(1, ins.front());
        for (int i = 1; i < ins.size(); ++i)
        {
            if (res.back().end < ins[i].start)
            {
                res.push_back(ins[i]);
            }
            else
            {
                res.back().end = max(res.back().end, ins[i].end);
            }
        }
        return res;
    }
};