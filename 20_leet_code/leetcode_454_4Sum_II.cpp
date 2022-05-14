#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
    {
        map<int, int> AB;
        for (auto &a : A)
        {
            for (auto &b : B)
            {
                AB[a + b]++;
            }
        }
        vector<int> kAB(0);
        for (const auto &p : AB)
        {
            kAB.push_back(p.first);
        }

        map<int, int> CD;
        for (auto &c : C)
        {
            for (auto &d : D)
            {
                CD[-(c + d)]++;
            }
        }
        vector<int> kCD(0);
        for (const auto &p : CD)
        {
            kCD.push_back(p.first);
        }
        int total(0), i(0), j(0);
        while (i < kAB.size() && j < kCD.size())
        {
            if (kAB[i] < kCD[j])
            {
                i++;
            }
            else if (kAB[i] > kCD[j])
            {
                j++;
            }
            else
            {
                total += AB[kAB[i++]] * CD[kCD[j++]];
            }
        }
        return total;
    }
};