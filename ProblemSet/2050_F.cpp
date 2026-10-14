#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b)
{
    while (b)
    {
        int r = a % b;
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
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        n--;
        vector<int> diff(max(0, n)), lg(n + 1, 0); // precompute log2
        for (int i = 0; i < n; i++)
            diff[i] = abs(a[i + 1] - a[i]);
        for (int i = 2; i <= n; i++)
            lg[i] = lg[i / 2] + 1;
        vector<vector<int>> st(lg[n] + 1, vector<int>(n)); // sparse table
        if (n > 0)
        {
            st[0] = diff;
            for (int k = 1; k <= lg[n]; k++)
                for (int i = 0; i + (1 << k) <= n; i++)
                    st[k][i] = gcd(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
        }
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            if (l == r)
            {
                cout << "0 ";
                continue;
            }
            int length = r - l;
            int k = lg[length];
            int m = gcd(st[k][l - 1], st[k][r - 1 - (1 << k)]);
            cout << m << " ";
        }
        cout << endl;
    }
    return 0;
}