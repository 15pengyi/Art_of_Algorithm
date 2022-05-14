#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        std::vector<std::vector<std::string>> parenthesis(1, std::vector<std::string>(1, ""));
        for (int i = 1; i <= n; ++i)
        {
            std::vector<std::string> p;
            for (int j = 0; j < i; j++)
            {
                for (auto p1 : parenthesis[j])
                {
                    for (auto p2 : parenthesis[i - 1 - j])
                    {
                        p.push_back("(" + p1 + ")" + p2);
                    }
                }
            }
            parenthesis.push_back(p);
        }
        return parenthesis[n];
    }
};