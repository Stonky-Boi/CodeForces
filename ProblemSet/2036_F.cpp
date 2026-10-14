#include <iostream>
using namespace std;

long long get_xor(long long n)
{
    if (n < 0)
        return 0;
    if (n % 4 == 0)
        return n;
    if (n % 4 == 1)
        return 1;
    if (n % 4 == 2)
        return n + 1;
    return 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long l, r, k;
        int i;
        cin >> l >> r >> i >> k;
        long long p = 1ll << i;
        long long total = get_xor(r) ^ get_xor(l - 1);
        long long first = l + (k - l % p + p) % p;
        long long last = r - (r % p - k + p) % p;
        long long excluded = 0;
        if (first <= r)
        {
            long long ql = (first - k) / p;
            long long qr = (last - k) / p;
            excluded = (get_xor(qr) ^ get_xor(ql - 1)) << i;
            long long count = qr - ql + 1;
            if (count % 2 == 1)
                excluded ^= k;
        }
        cout << (total ^ excluded) << endl;
    }
    return 0;
}