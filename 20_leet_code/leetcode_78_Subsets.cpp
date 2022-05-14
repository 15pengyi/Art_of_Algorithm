#include <vector>
#include <map>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &S)
    {
        if (S.size() == 0)
        {
            return std::vector<std::vector<int>>();
        }

        std::sort(S.begin(), S.end());

        std::vector<int> bits(S.size(), 1);
        for (int i = 1; i < S.size(); ++i)
        {
            bits[i] = bits[i - 1] << 1;
        }

        std::vector<std::vector<int>> ret;
        int size = 1 << S.size();
        for (int i = 0; i < size; ++i)
        {
            std::vector<int> set;
            for (int j = 0; j < S.size(); ++j)
            {
                if (i & bits[j])
                {
                    set.push_back(S[j]);
                }
            }
            ret.push_back(set);
        }
        return ret;
    }
};