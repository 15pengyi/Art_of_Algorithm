#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &num)
    {
        if (num.size() == 0)
        {
            return std::vector<std::vector<int>>();
        }

        std::vector<std::vector<int>> permutations(1, std::vector<int>(1, 0));
        for (int i = 1; i < num.size(); i++)
        {
            std::vector<std::vector<int>> permutation;
            for (const auto &p : permutations)
            {
                for (int j = 0; j <= p.size(); j++)
                {
                    std::vector<int> temp(p);
                    temp.insert(temp.begin() + j, i);
                    permutation.push_back(temp);
                }
            }
            permutations = permutation;
        }

        std::vector<std::vector<int>> ret;
        for (const auto &p : permutations)
        {
            std::vector<int> temp;
            for (const auto &i : p)
            {
                temp.push_back(num[i]);
            }
            ret.push_back(temp);
        }
        return ret;
    }
};