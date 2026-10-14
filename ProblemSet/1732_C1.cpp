#include <iostream>
#include <vector>
using namespace std;

long long get_value(int l, int r, vector<long long> &prefix_sum, vector<long long> &prefix_xor)
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
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        vector<long long> prefix_sum(n + 1, 0), prefix_xor(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            prefix_sum[i + 1] = prefix_sum[i] + a[i];
            prefix_xor[i + 1] = prefix_xor[i] ^ a[i];
        }
        while (q--)
        {
            int L, R;
            cin >> L >> R;
            long long target = get_value(L, R, prefix_sum, prefix_xor);
            int left = L;
            int right = R;
            for (int i = L; i <= R; i++)
            {
                if (get_value(i, R, prefix_sum, prefix_xor) < target)
                    continue;
                int l = i;
                int r = R;
                while (l < r)
                {
                    int m = l + (r - l) / 2;
                    if (get_value(i, m, prefix_sum, prefix_xor) >= target)
                        r = m;
                    else
                        l = m + 1;
                }
                if (l - i < right - left)
                {
                    left = i;
                    right = l;
                }
            }
            cout << left << " " << right << endl;
        }
    }
    return 0;
}