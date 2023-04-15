#include "util.h"
#include <math.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
    int* temp = a;
    a = b;
    b = temp;
}
int sq(int r) { return r * r; }
int natRoot(int d)
{
    int r = (int)sqrt(d);
    return sq(r) == d ? r : (sq(r + 1) == d ? r + 1 : -1);
}
int isPrime(int p)
{
    if (p <= 1)
        return 0;
    for (int i = 2; sq(i) <= p; i++)
        if (p % i == 0)
            return 0;
    return 1;
}
Euclid euclid(int a, int b)
{
    /* The theoretical upper bound on the number of steps in the worst-case scenario. */
    int upper = (int)(log(a * sqrt(5)) / log(phi)) - 1;
    Euclid data;
    data.n = 0;
    data.quot = (int*)malloc(sizeof(int) * upper);
    data.rem = (int*)malloc(sizeof(int) * upper);
    while (b > 0) {
        data.quot[data.n] = a / b;
        data.rem[data.n] = a % b;
        a = b;
        b = data.rem[data.n++];
    }
    return data;
}
void destroy_euclid(Euclid* e)
{
    free(e->quot);
    free(e->rem);
    free(e);
}
int gcd(int a, int b)
{
    if (a < b)
        swap(&a, &b);
    Euclid e = euclid(a, b);
    int ret = e.rem[e.n];
    destroy_euclid(&e);
    return ret;
}