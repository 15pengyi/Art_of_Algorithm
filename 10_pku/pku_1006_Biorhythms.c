#include <stdio.h>

int solve(int p, int q, int r)
{
    if (q == 0)
        return 0;
    else
        return (r - p * solve(q, p % q, r)) / q % p;
}

int main()
{
    int p, e, i, d, t, n = 0;

    scanf("%d %d %d %d", &p, &e, &i, &d);

    while (p >= 0)
    {
        n++;

        t = solve(23, -28, e - p);
        t = solve(23 * 28, -33, i - e - 28 * t);
        t = (t * 33 + i - d + 21252) % 21252;
        if (t == 0)
            t = 21252;

        printf("Case %d: the next triple peak occurs in %d days.\n", n, t);
        scanf("%d %d %d %d", &p, &e, &i, &d);
    }
    return 0;
}