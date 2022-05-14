#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *haab[] =
        {
            "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
    char *tzolkin[] =
        {
            "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

    int n;
    scanf("%d\n", &n);
    printf("%d\n", n);

    char buffer[16] = {0};
    for (int i = 0; i < n; i++)
    {
        int year, month, day;

        scanf("%s", buffer);
        buffer[strlen(buffer) - 1] = 0;
        day = atoi(buffer);

        scanf("%s", buffer);
        for (month = 0; month < 19; month++)
        {
            if (strcmp(buffer, haab[month]) == 0)
                break;
        }

        scanf("%s", buffer);
        year = atoi(buffer);

        int number = year * 365 + month * 20 + day;
        year = number / (20 * 13);
        number = number - year * (20 * 13);
        day = number % 13 + 1;
        month = number % 20;
        printf("%d %s %d\n", day, tzolkin[month], year);
    }

    return 0;
}