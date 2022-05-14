#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    void merge(int A[], int m, int B[], int n)
    {
        int i(0), j(0);
        std::vector<int> C;
        while (i < m && j < n)
        {
            C.push_back(A[i] < B[j] ? A[i++] : B[j++]);
        }
        if (i < m)
        {
            C.insert(C.end(), A + i, A + m);
        }
        if (j < n)
        {
            C.insert(C.end(), B + j, B + n);
        }
        int k(0);
        for (auto e : C)
        {
            A[k++] = e;
        }
    }
};