#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        vector<int> nums(1, 0);
        int total(0);
        vector<string> rTokens(tokens.rbegin(), tokens.rend());
        while (!rTokens.empty())
        {
            int opt(-1);
            string &s(rTokens.back());
            rTokens.pop_back();
            size_t pos(s.find_first_of("+-*/"));
            if (s.size() > 1 || pos == string::npos)
            {
                int num(stoi(s));
                nums.push_back(num);
                // cout << "num+: " << num << endl;
            }
            else
            {
                int r(nums.back());
                nums.pop_back();
                // cout << "num-: " << r << endl;
                int l(nums.back());
                nums.pop_back();
                // cout << "num-: " << l << endl;
                int res(0);
                switch (s[pos])
                {
                case '+':
                    res = l + r;
                    break;
                case '-':
                    res = l - r;
                    break;
                case '*':
                    res = l * r;
                    break;
                case '/':
                    res = l / r;
                    break;
                default:
                    break;
                }
                // cout << "opt: " << s[pos] << endl;
                nums.push_back(res);
                // cout << "num+: " << res << endl;
            }
        }
        return nums.back();
    }
};