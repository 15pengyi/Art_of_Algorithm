#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> lines(0);
        for (int i = 1; i <= n; ++i)
        {
            if (i % 3 == 0 && i % 5 == 0)
            {
                lines.push_back("FizzBuzz");
            }
            else if (i % 5 == 0)
            {
                lines.push_back("Buzz");
            }
            else if (i % 3 == 0)
            {
                lines.push_back("Fizz");
            }
            else
            {
                lines.push_back(std::to_string(i));
            }
        }
        return lines;
    }
};