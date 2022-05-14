#include <vector>
#include <map>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int calculate(string::reverse_iterator begin, string::reverse_iterator end)
    {
        string::reverse_iterator middle;
        string plus_minus("+-");
        if ((middle = find_first_of(begin, end, plus_minus.begin(), plus_minus.end())) != end)
        {
            if (*middle == '+')
            {
                return calculate(middle + 1, end) + calculate(begin, middle);
            }
            else
            {
                return calculate(middle + 1, end) - calculate(begin, middle);
            }
        }
        string mul_div("*/");
        if ((middle = find_first_of(begin, end, mul_div.begin(), mul_div.end())) != end)
        {
            if (*middle == '*')
            {
                return calculate(middle + 1, end) * calculate(begin, middle);
            }
            else
            {
                return calculate(middle + 1, end) / calculate(begin, middle);
            }
        }

        string r(begin, end);
        string s(r.rbegin(), r.rend());
        return stoi(s);
    }

    int calculate(string s)
    {
        s.erase(remove_if(s.begin(), s.end(), [](char x)
                          { return isspace(x); }),
                s.end());
        // return calculate(s.rbegin(), s.rend());

        vector<int> nums(0);
        vector<int> opts(0); // eof: 4, +: 3, -: 2, *: 1, /: 0
        size_t index(0);
        while (index < s.size())
        {
            int opt(-1);
            size_t pos(s.find_first_of("+-*/", index));
            if (pos == string::npos)
            {
                int num(stoi(s.substr(index)));
                nums.push_back(num);
                // cout << "num+: " << num << endl;
                opt = 4;
                index = s.size();
            }
            else
            {
                int num(stoi(s.substr(index, pos - index)));
                nums.push_back(num);
                // cout << "num+: " << num << endl;
                switch (s[pos])
                {
                case '+':
                    opt = 3;
                    break;
                case '-':
                    opt = 2;
                    break;
                case '*':
                    opt = 1;
                    break;
                case '/':
                    opt = 0;
                    break;
                default:
                    break;
                }
                index = pos + 1;
            }
            while (!opts.empty() && opt / 2 >= opts.back() / 2)
            {
                int r(nums.back());
                nums.pop_back();
                // cout << "num-: " << r << endl;
                int l(nums.back());
                nums.pop_back();
                // cout << "num-: " << l << endl;
                int o(opts.back());
                opts.pop_back();
                // cout << "opt-: " << o << endl;
                int res(0);
                switch (o)
                {
                case 3:
                    res = l + r;
                    break;
                case 2:
                    res = l - r;
                    break;
                case 1:
                    res = l * r;
                    break;
                case 0:
                    res = l / r;
                    break;
                default:
                    break;
                }
                nums.push_back(res);
                // cout << "num+: " << res << endl;
            }
            opts.push_back(opt);
            // cout << "opt+: " << opt << endl;
        }
        return nums.back();
    }
};