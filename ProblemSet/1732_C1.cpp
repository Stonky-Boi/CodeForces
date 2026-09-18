#include <iostream>
#include <vector>
using namespace std;

long long range_cost(int l, int r, const vector<long long> &prefix_sum, const vector<long long> &prefix_xor)
{
    long long s = prefix_sum[r] - prefix_sum[l - 1];
    long long x = prefix_xor[r] ^ prefix_xor[l - 1];
    return s - x;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<long long> prefix_sum(n + 1, 0);
        vector<long long> prefix_xor(n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            long long x;
            cin >> x;
            prefix_sum[i] = prefix_sum[i - 1] + x;
            prefix_xor[i] = prefix_xor[i - 1] ^ x;
        }
        int L, R;
        cin >> L >> R; // for C1: L==1, R==n
        long long best_cost = range_cost(1, n, prefix_sum, prefix_xor);
        int l = 1, r = n;
        while (l < r)
        {
            int m = l + (r - l) / 2;
            bool possible = false;
            for (int i = 1; i + m - 1 <= n; i++)
                if (range_cost(i, i + m - 1, prefix_sum, prefix_xor) == best_cost)
                {
                    possible = true;
                    break;
                }
            if (possible)
                r = m;
            else
                l = m + 1;
        }
        for (int i = 1; i + l - 1 <= n; i++)
            if (range_cost(i, i + l - 1, prefix_sum, prefix_xor) == best_cost)
            {
                cout << i << " " << (i + l - 1) << endl;
                break;
            }
    }
    return 0;
}