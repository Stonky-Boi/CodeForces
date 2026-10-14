#include <iostream>
using namespace std;

long long gcd(long long a, long long b)
{
    while (b)
    {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long lcm(long long a, long long b)
{
    return (a / gcd(a, b)) * b;
}

long long sum(long long a, long long b)
{
    return (a + b) * (b - a + 1) / 2;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, x, y;
        cin >> n >> x >> y;
        long long common = n / lcm(x, y);
        long long n1 = n / x - common, n2 = n / y - common;
        cout << sum(n - n1 + 1, n) - sum(1, n2) << endl;
    }
    return 0;
}