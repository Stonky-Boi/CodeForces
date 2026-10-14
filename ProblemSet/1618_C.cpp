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

long long check(vector<long long> &a, int offset)
{
    long long g = 0;
    for (int i = offset; i < a.size(); i += 2)
        g = gcd(g, a[i]);
    for (int i = 1 - offset; i < a.size(); i += 2)
    {
        if (a[i] % g == 0)
            return 0;
    }
    return g;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (long long &i : a)
            cin >> i;
        cout << max(check(a, 0), check(a, 1)) << endl;
    }
    return 0;
}