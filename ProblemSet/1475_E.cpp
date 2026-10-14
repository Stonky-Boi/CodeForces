#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int MOD = 1e9 + 7;
    int MAXN = 1000;
    long long C[MAXN + 1][MAXN + 1];
    for (int i = 0; i <= MAXN; i++)
    {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        sort(a.begin(), a.end(), greater<int>());
        int last = a[k - 1];
        int needed = 0;
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == last)
            {
                total++;
                if (i < k)
                    needed++;
            }
        }
        cout << C[total][needed] << endl;
    }
    return 0;
}