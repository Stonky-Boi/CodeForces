#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k, b, s;
        cin >> n >> k >> b >> s;
        if (k * b > s || s > k * b + (k - 1) * n)
        {
            cout << -1 << endl;
            continue;
        }
        vector<long long> a(n, 0);
        a[0] = k * b;
        s -= k * b;
        for (long long &i : a)
        {
            long long add = min(k - 1, s);
            i += add;
            s -= add;
        }
        for (const long long &i : a)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}