#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        if (s.size() == 0)
        {
            return true;
        }

        std::map<char, char> matches{
            {'(', ')'},
            {'{', '}'},
            {'[', ']'}};
        std::vector<char> stack;
        for (auto c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                stack.push_back(c);
            }
            else
            {
                if (stack.empty() || c != matches[stack.back()])
                {
                    return false;
                }
                else
                {
                    stack.pop_back();
                }
            }
        }
        return stack.empty();
    }
};