#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int MOD = 998244353;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    vector<vector<long long>> curr(2, vector<long long>(2, 0));
    vector<long long> single(2, 0);
    long long sequences = 0;
    for (int i = 0; i < n; i++)
    {
        int p = a[i] % 2;
        vector<vector<long long>> next(2, vector<long long>(2, 0));
        for (int x = 0; x < 2; x++)
        {
            for (int y = 0; y < 2; y++)
            {
                if ((x + y + p) % 2 == 0)
                {
                    next[y][p] = (next[y][p] + curr[x][y]) % MOD;
                    sequences = (sequences + curr[x][y]) % MOD;
                }
            }
        }
        for (int x = 0; x < 2; x++)
            next[x][p] = (next[x][p] + single[x]) % MOD;
        for (int x = 0; x < 2; x++)
        {
            for (int y = 0; y < 2; y++)
                curr[x][y] = (curr[x][y] + next[x][y]) % MOD;
        }
        single[p] = (single[p] + 1) % MOD;
    }
    cout << sequences << endl;
    return 0;
}