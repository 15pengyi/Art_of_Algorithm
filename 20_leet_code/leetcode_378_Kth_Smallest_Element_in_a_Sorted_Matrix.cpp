#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    int kthSmallest(vector<vector<int>> &arr, int k)
    {
        if (arr.empty())
        {
            return false;
        }
        int m = arr.size();
        int n = arr.front().size();
        int left = arr[0][0], right = arr[m - 1][n - 1];
        while (left < right)
        {
            int middle = left + (right - left) / 2;
            int num = count(arr, middle);
            if (num < k)
            {
                left = middle + 1;
            }
            else
            {
                right = middle;
            }
        }
        return left;
    }

    int count(const vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix.front().size();
        int i = m - 1, j = 0, count = 0;
        while (i >= 0 && j < n)
        {
            if (matrix[i][j] <= target)
            {
                count += i + 1;
                j++;
            }
            else
            {
                i--;
            }
        }
        return count;
    }
};