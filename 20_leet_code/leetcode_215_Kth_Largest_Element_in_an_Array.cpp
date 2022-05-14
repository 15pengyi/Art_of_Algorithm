#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k, int start, int end)
    {
        if (nums.size() == 1)
        {
            return nums.front();
        }
        int left(start + 1), right(end);
        while (left <= right)
        {
            if (nums[left] < nums[start])
            {
                swap(nums, left, right);
                right--;
            }
            else
            {
                left++;
            }
        }
        int pivot(left - 1);
        swap(nums, start, pivot);

        int size(pivot - start + 1);
        if (size == k)
        {
            return nums[pivot];
        }
        else if (size > k)
        {
            return findKthLargest(nums, k, start, pivot - 1);
        }
        else
        {
            return findKthLargest(nums, k - size, pivot + 1, end);
        }
    }

    int findKthLargest(vector<int> &nums, int k)
    {
        if (k <= 0 || k > nums.size())
        {
            return 0;
        }
        return findKthLargest(nums, k, 0, nums.size() - 1);
    }

    void swap(vector<int> &nums, int x, int y)
    {
        int t(nums[x]);
        nums[x] = nums[y];
        nums[y] = t;
    }
};