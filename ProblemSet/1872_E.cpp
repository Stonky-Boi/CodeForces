#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n);
        ;
        for (auto &i : a)
            cin >> i;
        string s;
        cin >> s;
        vector<long long> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++)
            prefix[i] = prefix[i - 1] ^ a[i - 1];
        long long xor_zero = 0, xor_one = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                xor_zero ^= a[i];
            else
                xor_one ^= a[i];
        }
        int q;
        cin >> q;
        while (q--)
        {
            int type;
            cin >> type;
            if (type == 1)
            {
                int l, r;
                cin >> l >> r;
                long long segment_xor = prefix[r] ^ prefix[l - 1];
                xor_zero ^= segment_xor;
                xor_one ^= segment_xor;
            }
            else
            {
                int g;
                cin >> g;
                cout << (g == 0 ? xor_zero : xor_one) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}