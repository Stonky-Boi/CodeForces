#include <iostream>
#include <vector>
#include <algorithm>
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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (long long &i : a)
            cin >> i;
        sort(a.begin(), a.end());
        long long k = 0;
        for (int i = 1; i < n; i++)
            k = gcd(k, a[i] - a[i - 1]);
        k *= 2;
        cout << k << endl;
    }
    return 0;
}