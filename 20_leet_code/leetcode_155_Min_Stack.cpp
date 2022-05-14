#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class MinStack
{
public:
    vector<int> stack;
    vector<int> buffer;

    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        stack.push_back(x);
        if (buffer.empty() || x <= buffer.back())
        {
            buffer.push_back(x);
        }
    }

    void pop()
    {
        if (stack.back() == buffer.back())
        {
            buffer.pop_back();
        }
        stack.pop_back();
    }

    int top()
    {
        return stack.back();
    }

    int getMin()
    {
        return buffer.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */