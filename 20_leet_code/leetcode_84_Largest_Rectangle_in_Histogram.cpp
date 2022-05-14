#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        vector<pair<int, int>> stack(0);
        vector<int> right(heights.size());
        for (int i = heights.size() - 1; i >= 0; --i)
        {
            int h(heights[i]);
            while (!stack.empty() && h <= stack.back().first)
            {
                // cout << "R-: " << stack.back().first << endl;
                stack.pop_back();
            }
            if (stack.empty())
            {
                right[i] = heights.size() - 1;
            }
            else
            {
                right[i] = stack.back().second - 1;
            }
            stack.push_back({h, i});
            // cout << "R+: " << stack.back().first << endl;
            // cout << "R" << i << ": " << right[i] << endl;
        }

        stack.clear();
        vector<int> left(heights.size());
        for (int i = 0; i < heights.size(); ++i)
        {
            int h(heights[i]);
            while (!stack.empty() && h < stack.back().first)
            {
                // cout << "L-: " << stack.back().first << endl;
                stack.pop_back();
            }
            if (stack.empty())
            {
                left[i] = 0;
            }
            else
            {
                left[i] = stack.back().second + 1;
            }
            stack.push_back({h, i});
            // cout << "L+: " << stack.back().first << endl;
            // cout << "L" << i << ": " << left[i] << endl;
        }

        int area(0);
        for (int i = 0; i < heights.size(); ++i)
        {
            int h(heights[i]);
            int w(right[i] - left[i] + 1);
            area = max(area, w * h);
        }
        return area;
    }
};