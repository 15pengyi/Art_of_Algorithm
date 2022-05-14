#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

int trailingZeroes(int n)
{
    int number = 0;
    while (n > 0)
    {
        n /= 5;
        number += n;
    }
    return number;
}