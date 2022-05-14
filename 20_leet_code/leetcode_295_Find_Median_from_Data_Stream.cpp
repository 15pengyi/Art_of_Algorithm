#include <vector>
#include <map>
#include <string>
#include <set>
#include <limits>

using namespace std;

class MedianFinder
{
public:
    multiset<int> left, right;

    /** initialize your data structure here. */
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (left.empty() || right.empty())
        {
            if (right.empty())
            {
                left.insert(num);
            }
            else
            {
                right.insert(num);
            }
        }
        else
        {
            if (num <= *right.begin())
            {
                left.insert(num);
            }
            else
            {
                right.insert(num);
            }
        }
        if (left.size() > right.size() + 1)
        {
            int v(*left.rbegin());
            left.erase(next(left.rbegin()).base());
            right.insert(v);
        }
        if (right.size() > left.size() + 1)
        {
            int v(*right.begin());
            right.erase(right.begin());
            left.insert(v);
        }
    }

    double findMedian()
    {
        if (left.size() != right.size())
        {
            if (left.size() > right.size())
            {
                return *left.rbegin();
            }
            else
            {
                return *right.begin();
            }
        }
        else
        {
            if (left.empty() || right.empty())
            {
                return -1;
            }
            else
            {
                return (*left.rbegin() + *right.begin()) * 0.5;
            }
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */