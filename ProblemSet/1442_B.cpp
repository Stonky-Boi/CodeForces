#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int MOD = 998244353;
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(k);
        vector<int> position(n + 1), when(n + 1, -1);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            position[a[i]] = i;
        }
        for (int i = 0; i < k; i++)
        {
            cin >> b[i];
            when[b[i]] = i;
        }
        vector<int> left(n), right(n);
        for (int i = 0; i < n; i++)
        {
            left[i] = i - 1;
            right[i] = i + 1;
            if (i == n - 1)
                right[i] = -1;
        }
        long long sequences = 1;
        for (int i = 0; i < k; i++)
        {
            int p = position[b[i]];
            int L = left[p];
            int R = right[p];
            bool can_left = L != -1 && when[a[L]] < i;
            bool can_right = R != -1 && when[a[R]] < i;
            int count = can_left + can_right;
            if (count == 0)
            {
                sequences = 0;
                break;
            }
            sequences = (sequences * count) % MOD;
            int x = can_left ? L : R;
            int l = left[x];
            int r = right[x];
            if (l != -1)
                right[l] = r;
            if (r != -1)
                left[r] = l;
        }
        cout << sequences << endl;
    }
    return 0;
}