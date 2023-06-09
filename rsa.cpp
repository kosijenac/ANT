#include <iostream>

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int kongruencija(int a, int m, int n)
{
    int aa = 1;
    for (int i = 1; i <= m; i++) {
        aa = aa * a;
        aa = aa % n;
    }
    return aa;
}
int main()
{
    int n = 3496687;
    int e = 17;
    int d = 479393;
    int m = e * d - 1;
    int k = 0;
    m = m / 2;
    k++;
    for (int a = 2; 1; a++) {
        if (gcd(a, n) != 1)
            continue;
        if (kongruencija(a, m, n) != 1) {
            std::cout << kongruencija(a, m, n) << std::endl;
            std::cout << "k = " << k << ", a = " << a << std::endl;
            break;
        }
        if (a == 201) {
            if (m % 2 != 0)
                break;
            a = 2;
            m = m / 2;
            k++;
        }
    }
    return 0;
}
