#include <iostream>
#include <vector>
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

int main()
{
    int n, m;
    cin >> n >> m;
    vector<long long> a(n), b(m);
    for (long long &i : a)
        cin >> i;
    for (long long &i : b)
        cin >> i;
    long long g = 0;
    for (int i = 1; i < n; i++)
        g = gcd(g, abs(a[i] - a[0]));
    for (int i = 0; i < m; i++)
        cout << gcd(a[0] + b[i], g) << " ";
    cout << endl;
    return 0;
}