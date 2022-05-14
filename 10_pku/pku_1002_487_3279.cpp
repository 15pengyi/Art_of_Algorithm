#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

int compare(const void *a, const void *b)
{
    return *((int *)a) - *((int *)b);
}

int main()
{
    int i, j, k, num, cal, value = 1;
    cin >> num;
    char a[100], b[8];
    const char con[] = "22233344455566677778889999";
    int *c = new int[num];
    for (i = 0; i < num; i++)
    {
        cin >> a;
        k = 0;
        for (j = 0; a[j]; j++)
        {
            if (a[j] >= 'A' && a[j] <= 'Z')
            {
                b[k] = con[a[j] - 'A'];
                k++;
                continue;
            }
            if (a[j] >= '0' && a[j] <= '9')
            {
                b[k] = a[j];
                k++;
            }
        }
        c[i] = atoi(b);
    }

    qsort(c, num, sizeof(int), compare);

    for (i = 0; i < num;)
    {
        cal = 1;
        for (j = i + 1; j < num && c[j] == c[i]; j++)
            cal++;
        if (cal > 1)
        {
            value = 0;
            cout << setfill('0') << setw(3) << c[i] / 10000 << "-" << setfill('0') << setw(4) << c[i] % 10000 << " " << cal << endl; //
        }
        i = j;
    }
    if (value)
        cout << "No duplicates." << endl;
    delete[] c;

    return 0;
}
