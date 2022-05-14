#include <vector>
#include <map>
#include <string>
#include <list>
#include <limits>

using namespace std;

class NestedInteger
{
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator
{
    vector<int> list_;
    vector<int>::iterator itr_;

public:
    NestedIterator(vector<NestedInteger> &nestedList) : list_(), itr_()
    {
        list<NestedInteger> queue(nestedList.begin(), nestedList.end());
        while (!queue.empty())
        {
            NestedInteger n(queue.front());
            queue.pop_front();
            if (n.isInteger())
            {
                list_.push_back(n.getInteger());
            }
            else
            {
                const vector<NestedInteger> &l(n.getList());
                for (auto i = l.rbegin(); i != l.rend(); ++i)
                {
                    queue.push_front(*i);
                }
            }
        }
        itr_ = list_.begin();
    }

    int next()
    {
        if (hasNext())
        {
            return *(itr_++);
        }
        else
        {
            return 0;
        }
    }

    bool hasNext()
    {
        return itr_ != list_.end();
    }
};

/**
Your NestedIterator object will be instantiated and called as such:
NestedIterator i(nestedList);
while (i.hasNext()) cout << i.next();
 */
