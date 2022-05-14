#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        string say("1");
        for (int i = 1; i < n; ++i)
        {
            string sayNext("");
            char c(say.front());
            int count(1);
            for (int j = 1; j < say.size(); ++j)
            {
                if (say[j] == say[j - 1])
                {
                    count += 1;
                }
                else
                {
                    sayNext += to_string(count);
                    sayNext += c;
                    c = say[j];
                    count = 1;
                }
            }
            sayNext += to_string(count);
            sayNext += c;
            say = sayNext;
        }
        return say;
    }
};