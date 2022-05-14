#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left(0);
        int right(height.size() - 1);
        int area(0);
        while (left < right)
        {
            area = max(area, min(height[left], height[right]) * (right - left));
            if (height[left] <= height[right])
            {
                ++left;
                while (left < right && height[left] <= height[right])
                {
                    area = max(area, min(height[left], height[right]) * (right - left));
                    ++left;
                }
            }
            else
            {
                --right;
                while (left < right && height[right] <= height[left])
                {
                    area = max(area, min(height[left], height[right]) * (right - left));
                    --right;
                }
            }
        }
        return area;
    }
};