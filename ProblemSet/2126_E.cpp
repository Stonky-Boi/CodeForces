#include <iostream>
using namespace std;

long long gcd(long long a, long long b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

long long lcm(long long a, long long b)
{
    return a * b / gcd(a, b);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long int n;
        cin >> n;
        long long int p[n], s[n], a[n], prefix[n], suffix[n];
        for (int i = 0; i < n; i++)
            cin >> p[i];
        for (int i = 0; i < n; i++)
            cin >> s[i];
        for (int i = 0; i < n; i++)
            a[i] = lcm(p[i], s[i]);
        prefix[0] = a[0];
        for (int i = 1; i < n; i++)
            prefix[i] = gcd(prefix[i - 1], a[i]);
        suffix[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--)
            suffix[i] = gcd(suffix[i + 1], a[i]);
        bool valid = true;
        for (int i = 0; i < n; i++)
        {
            if (prefix[i] != p[i] || suffix[i] != s[i])
            {
                valid = false;
                break;
            }
        }
        cout << (valid ? "YES" : "NO") << endl;
    }
    return 0;
}