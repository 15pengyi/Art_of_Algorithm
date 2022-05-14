#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

int absi(int x, int y)
{
    return x > y ? x - y : y - x;
}

int getid(int (*ends)[2], int count, int x)
{
    if (x < ends[0][0] || x > ends[count - 1][1])
    {
        return -1;
    }
    else
    {
        int start = 0, end = count - 1;
        while (start < end)
        {
            int middle = (start + end) / 2;
            if (ends[middle][1] < x)
            {
                start = middle + 1;
            }
            else
            {
                end = middle;
            }
        }
        return start;
    }
}

void echo(int (*pairs)[2], int (*ends)[2], int count, int width, int x, int y, int *pvalue, int *plength)
{
    int dt[8][2] =
        {
            {-1, -1},
            {-1, 0},
            {-1, 1},
            {0, -1},
            {0, 1},
            {1, -1},
            {1, 0},
            {1, 1}};

    int value = 0, length = y - x + 1;
    int v = pairs[getid(ends, count, x)][0];
    for (int i = 0; i < 8; i++)
    {
        int row = x / width + dt[i][0];
        int col = x % width + dt[i][1];
        if (0 <= col && col < width && 0 <= row && row < (ends[count - 1][1] + 1) / width)
        {
            int temp = absi(pairs[getid(ends, count, row * width + col)][0], v);
            value = temp > value ? temp : value;
        }
    }

    if (*pvalue != -1)
    {
        if (*pvalue == value)
        {
            length = *plength + y - x + 1;
        }
        else
        {
            printf("%d %d\n", *pvalue, *plength);
        }
    }
    *pvalue = value;
    *plength = length;
}

void print(int (*pairs)[2], int (*ends)[2], int count, int width, int x, int y, int *pvalue, int *plength)
{
    int recurse = 0;
    int previous = -1, next = -1;
    if (x < y)
    {
        if (!recurse && (x % width == 0))
        {
            if (x / width == y / width)
            {
                if (y % width == width - 1)
                {
                    int id1 = getid(ends, count, x - width);
                    int id2 = getid(ends, count, y - width);
                    if (id1 == id2)
                    {
                        previous = id1;
                    }
                    else
                    {
                        recurse = 1;
                    }
                }
                else
                {
                    recurse = 1;
                }
            }
            else
            {
                int id1 = getid(ends, count, x - width);
                int id2 = getid(ends, count, x / width * width - 1);
                if (id1 == id2)
                {
                    previous = id1;
                }
                else
                {
                    recurse = 1;
                }
            }
        }
        if (!recurse && (x % width > 0))
        {
            if (x >= width)
            {
                int id1 = getid(ends, count, x - width - 1);
                int id2 = getid(ends, count, x - 1);
                if (id1 == id2)
                {
                    previous = id1;
                }
                else
                {
                    recurse = 1;
                }
            }
            else
            {
                recurse = 1;
            }
        }
        if (!recurse && (y % width < width - 1))
        {
            if (y <= ends[count - 1][1] - width)
            {
                int id1 = getid(ends, count, y + width + 1);
                int id2 = getid(ends, count, y + 1);
                if (id1 == id2)
                {
                    next = id1;
                }
                else
                {
                    recurse = 1;
                }
            }
            else
            {
                recurse = 1;
            }
        }
        if (!recurse && (y % width == width - 1))
        {
            if (x / width == y / width)
            {
                if (x % width == 0)
                {
                    int id1 = getid(ends, count, x + width);
                    int id2 = getid(ends, count, y + width);
                    if (id1 == id2)
                    {
                        next = id1;
                    }
                    else
                    {
                        recurse = 1;
                    }
                }
                else
                {
                    recurse = 1;
                }
            }
            else
            {
                int id1 = getid(ends, count, y + width);
                int id2 = getid(ends, count, y / width * (width + 1));
                if (id1 == id2)
                {
                    next = id1;
                }
                else
                {
                    recurse = 1;
                }
            }
        }
    }
    if (!recurse && previous != next && (x / width != y / width))
    {
        recurse = 1;
    }

    if (!recurse)
    {
        echo(pairs, ends, count, width, x, y, pvalue, plength);
    }
    else
    {
        print(pairs, ends, count, width, x, (x + y) / 2, pvalue, plength);
        print(pairs, ends, count, width, (x + y) / 2 + 1, y, pvalue, plength);
    }
}

int main()
{
    int pairs[MAX][2] = {0};
    int ends[MAX][2] = {0};
    int width;
    scanf("%d", &width);
    printf("%d\n", width);
    while (width > 0)
    {
        int value, length;
        int count = 0, number = 0;
        scanf("%d %d", &value, &length);
        while (value + length > 0)
        {
            pairs[count][0] = value;
            pairs[count][1] = length;
            ends[count][0] = number;
            if (count > 0)
                ends[count - 1][1] = number - 1;
            number += length;
            count++;
            scanf("%d %d", &value, &length);
        }
        if (count > 0)
            ends[count - 1][1] = number - 1;

        int pvalue = -1, plength = -1;
        for (int i = 0; i < count; i++)
        {
            print((int(*)[2])pairs, (int(*)[2])ends, count, width, ends[i][0], ends[i][1], &pvalue, &plength);
        }
        printf("%d %d\n", pvalue, plength);
        printf("0 0\n");

        scanf("%d", &width);
        printf("%d\n", width);
    }

    return 0;
}