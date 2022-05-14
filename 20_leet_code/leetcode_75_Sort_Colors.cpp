#include <vector>
#include <map>
#include <string>
#include <limits>

using namespace std;

class Solution
{
public:
    void sortColors(int A[], int n)
    {
        int numRed(0), numWhite(0), numBlue(0);
        for (int i = 0; i < n; i++)
        {
            int m = A[i];
            if (m == 0)
            {
                ++numRed;
            }
            else if (m == 1)
            {
                ++numWhite;
            }
            else
            {
                ++numBlue;
            }
        }
        for (int i = 0; i < numRed; i++)
        {
            A[i] = 0;
        }
        for (int i = numRed; i < numRed + numWhite; i++)
        {
            A[i] = 1;
        }
        for (int i = numRed + numWhite; i < n; i++)
        {
            A[i] = 2;
        }
    }
};