#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites)
    {
        vector<vector<int>> parents(numCourses);
        for (const auto &p : prerequisites)
        {
            parents[p.first].push_back(p.second);
        }
        for (int i = 0; i < numCourses; ++i)
        {
            vector<bool> visited(numCourses, false);
            vector<int> queue(1, i);
            while (!queue.empty())
            {
                int c(queue.back());
                queue.pop_back();
                if (visited[c])
                {
                    if (c == i)
                    {
                        return false;
                    }
                    else
                    {
                        continue;
                    }
                }
                visited[c] = true;
                for (const auto &p : parents[c])
                {
                    queue.push_back(p);
                }
            }
        }
        return true;
    }
};