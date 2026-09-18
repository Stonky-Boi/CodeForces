#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long c, k;
        cin >> n >> c >> k;
        long long a[n];
        for (auto &i : a)
            cin >> i;
        sort(a, a + n);
        for (auto i : a)
        {
            if (i > c)
                break;
            long long flip_flops = min(k, c - i);
            c += i + flip_flops;
            k -= flip_flops;
        }
        cout << c << endl;
    }
    return 0;
}