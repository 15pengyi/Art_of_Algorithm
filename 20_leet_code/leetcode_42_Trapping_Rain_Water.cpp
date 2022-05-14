#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        if (height.size() < 2)
        {
            return 0;
        }

        int start = 0;
        int end = height.size() - 1;
        int h = 0;
        int trap = 0;
        while (start < end)
        {
            int hMin = std::min<int>(height[start], height[end]);
            if (hMin > h)
            {
                trap -= h;
                trap += (hMin - h) * (end - start - 1);
                h = hMin;
            }
            else
            {
                trap -= hMin;
            }
            if (height[start] < height[end])
            {
                start++;
            }
            else
            {
                end--;
            }
        }
        return trap;
    }
};