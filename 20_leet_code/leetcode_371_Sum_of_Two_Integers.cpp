#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    int getSum(int a, int b)
    {
        int add(a ^ b);
        int carry(a & b);
        while (carry != 0)
        {
            a = add;
            b = carry << 1;
            add = a ^ b;
            carry = a & b;
        }
        return add;
    }
};