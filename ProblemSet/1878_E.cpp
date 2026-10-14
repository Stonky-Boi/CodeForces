#include <iostream>
#include <vector>
using namespace std;

int bits = 31;

int get_and(vector<vector<int>> &prefix_count, int l, int i)
{
    int value = 0;
    for (int b = 0; b < bits; b++)
    {
        if (prefix_count[i + 1][b] - prefix_count[l][b] == i - l + 1)
            value |= (1 << b);
    }
    return value;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        vector<vector<int>> prefix_count(n + 1, vector<int>(bits, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int b = 0; b < bits; b++)
            {
                prefix_count[i][b] = prefix_count[i - 1][b];
                if (a[i - 1] & (1 << b))
                    prefix_count[i][b]++;
            }
        }
        int q;
        cin >> q;
        while (q--)
        {
            int l, k;
            cin >> l >> k;
            l--;
            int left = l, right = n - 1;
            int r = -1;
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (get_and(prefix_count, l, mid) >= k)
                {
                    r = mid;
                    left = mid + 1;
                }
                else
                    right = mid - 1;
            }
            cout << (r == -1 ? -1 : r + 1) << " ";
        }
        cout << endl;
    }
    return 0;
}