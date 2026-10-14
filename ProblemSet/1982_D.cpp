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
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> a(n, vector<int>(m));
        for (vector<int> &v : a)
            for (int &i : v)
                cin >> i;
        vector<string> s(n);
        for (string &i : s)
            cin >> i;
        long long difference = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (s[i][j] == '0')
                    difference += a[i][j];
                else
                    difference -= a[i][j];
            }
        }
        if (difference == 0)
        {
            cout << "YES" << endl;
            continue;
        }
        vector<vector<int>> prefix_sum(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                prefix_sum[i + 1][j + 1] = prefix_sum[i][j + 1] + prefix_sum[i + 1][j] - prefix_sum[i][j] + (s[i][j] == '0' ? 1 : -1);
        int g = 0;
        for (int i = k; i <= n; i++)
            for (int j = k; j <= m; j++)
            {
                int d = prefix_sum[i][j] - prefix_sum[i - k][j] - prefix_sum[i][j - k] + prefix_sum[i - k][j - k];
                g = gcd(g, abs(d));
            }
        cout << (g != 0 && difference % g == 0 ? "YES" : "NO") << endl;
    }
    return 0;
}