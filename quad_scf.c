#include "util.h"
#include <stdio.h>
#include <stdlib.h>

#define PERIOD_LIMIT 256

void print_scf(int* a, int n, int period)
{
    printf("[%d; ", a[0]);
    for (int i = 1; i < n - 1; i++)
        i == period ? printf("(%d, ", a[i]) : printf("%d, ", a[i]);
    period == -1 ? printf("%d]\n", a[n - 1]) : printf("%d)]\n", a[n - 1]);
}

int check_period(int* s, int* t, int n)
{
    for (int i = 1; i < n; i++)
        if (s[i] == s[n] && t[i] == t[n])
            return i;
    return -1;
}

int main(int argc, char* argv[])
{
    if (argc != 4) {
        printf("Run as: %s <s0> <d> <t0>,\n", argv[0]);
        printf("where the quadratic irrational is of the form (s0 + √d)/t0");
        return -1;
    }
    int s0 = atoi(argv[1]), d = atoi(argv[2]), t0 = atoi(argv[3]);
    if (t0 == 0) {
        printf("Denominator may not be equal to 0.\n");
        return -2;
    }
    int root = natRoot(d);
    if (root != -1) {
        Euclid* e = euclid(s0 + root, t0);
        printf("Finite continued fraction: ");
        print_scf(e->quot, e->n, -1);
        destroy_euclid(e);
        return 0;
    }
    if ((d - sq(s0)) % t0) {
        s0 *= t0;
        d *= sq(t0);
        t0 *= t0;
    }
    int a[PERIOD_LIMIT], s[PERIOD_LIMIT], t[PERIOD_LIMIT], i = 0, period = -1;
    s[0] = s0;
    t[0] = t0;
    while (period == -1) {
        a[i] = (int)((s[i] + sqrt(d)) / t[i]);
        s[i + 1] = a[i] * t[i] - s[i];
        t[i + 1] = (d - sq(s[i + 1])) / t[i];
        period = check_period(s, t, ++i);
    }
    printf("Periodic continued fraction: ");
    print_scf(a, i, period);
    return 0;
}