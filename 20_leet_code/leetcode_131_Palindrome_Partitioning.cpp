#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    bool isPalindrome(std::string::iterator begin, std::string::iterator end)
    {
        if (end - begin < 2)
        {
            return true;
        }
        auto front = begin;
        auto back = end - 1;
        while (front < back)
        {
            if (*(front++) != *(back--))
            {
                return false;
            }
        }
        return true;
    }

    std::vector<std::vector<std::string>> partition(std::string::iterator begin, std::string::iterator end)
    {
        if (end - begin == 0)
        {
            return std::vector<std::vector<std::string>>();
        }

        std::vector<std::vector<std::string>> ret;
        int size = end - begin;
        for (int i = 1; i < size; ++i)
        {
            if (isPalindrome(begin, begin + i))
            {
                std::vector<std::vector<std::string>> right = partition(begin + i, end);
                for (auto &list : right)
                {
                    list.insert(list.begin(), std::string(begin, begin + i));
                }
                ret.insert(ret.end(), right.begin(), right.end());
            }
        }
        if (isPalindrome(begin, end))
        {
            ret.push_back(std::vector<std::string>(1, std::string(begin, end)));
        }
        return ret;
    }

    vector<vector<string>> partition(string s)
    {
        return partition(s.begin(), s.end());
    }
};