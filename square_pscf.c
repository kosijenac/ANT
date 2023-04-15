#include "util.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define PERIOD_LIMIT 256

int check_period(int* s, int* t, int n)
{
    for (int i = 1; i < n; i++)
        if (s[i] == s[n] && t[i] == t[n])
            return i;
    return -1;
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("Run as: %s <period_length>\n", argv[0]);
        return -1;
    }
    int length = atoi(argv[1]), found = 0, d = 1;
    if (length < 1) {
        printf("Period length must be positive.\n");
        return -2;
    }
    while (!found) {
        if (natRoot(++d) != -1) {
            printf("Skipping %d (perfect square).\n", d);
            continue;
        }
        int a[PERIOD_LIMIT], s[PERIOD_LIMIT], t[PERIOD_LIMIT], i = 0, period = -1;
        s[0] = 0;
        t[0] = 1;
        while (period == -1) {
            a[i] = (int)((s[i] + sqrt(d)) / t[i]);
            s[i + 1] = a[i] * t[i] - s[i];
            t[i + 1] = (d - sq(s[i + 1])) / t[i];
            period = check_period(s, t, ++i);
        }
        printf("Period length for √%d: %d\n", d, i - period);
        found = (i - period == length);
    }
    return 0;
}