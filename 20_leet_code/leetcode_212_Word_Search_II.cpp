#include <vector>
#include <map>
#include <string>
#include <set>
#include <limits>

using namespace std;

class Solution
{
public:
    vector<pair<int, int>> directions;
    int rows, cols;

    bool search(vector<vector<char>> &board, const string &word, vector<int> &path, vector<int> &visit)
    {
        if (path.size() == word.size())
        {
            return true;
        }

        int index(path.back());
        int row(index / cols);
        int col(index % cols);
        for (int i = 0; i < 4; ++i)
        {
            int r(row + directions[i].first);
            int c(col + directions[i].second);
            int idx(r * cols + c);
            if (r >= 0 && r < rows && c >= 0 && c < cols &&
                !visit[idx] && board[r][c] == word[path.size()])
            {
                // cout << "+ (" << r << ", " << c << "): " << word[path.size()] << endl;
                visit[idx] = true;
                path.push_back(idx);
                int ret = search(board, word, path, visit);
                if (ret)
                {
                    return true;
                }
                path.pop_back();
                visit[idx] = false;
                // cout << "- (" << r << ", " << c << "): " << word[path.size()] << endl;
            }
        }
        return false;
    }

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        if (board.empty())
        {
            return vector<string>();
        }
        directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        vector<string> res;
        for (const auto &word : set<string>(words.begin(), words.end()))
        {
            if (!word.empty() && exist(board, word))
            {
                res.push_back(word);
            }
        }
        return res;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        rows = board.size();
        cols = board.front().size();
        vector<int> path(0);
        vector<int> visit(rows * cols, false);
        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c)
            {
                if (board[r][c] == word.front())
                {
                    int index(r * cols + c);
                    // cout << "+ (" << r << ", " << c << "): " << word[path.size()] << endl;
                    visit[index] = true;
                    path.push_back(index);
                    int ret = search(board, word, path, visit);
                    if (ret)
                    {
                        return true;
                    }
                    path.pop_back();
                    visit[index] = false;
                }
            }
        }
        return false;
    }
};