#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        long long x;
        cin >> n >> k >> x;
        long long minimum_sum = 1ll * k * (k + 1) / 2;
        long long maximum_sum = 1ll * n * (n + 1) / 2 - 1ll * (n - k) * (n - k + 1) / 2;
        cout << ((minimum_sum <= x && x <= maximum_sum) ? "YES" : "NO") << endl;
    }
    return 0;
}