#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    const long long MOD = 1000000007;
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    vector<long long> pow2(n + 1);
    pow2[0] = 1;
    for (int i = 1; i <= n; i++)
        pow2[i] = (pow2[i - 1] * 2) % MOD;
    long long answer = 0;
    for (int m = n; m >= 2; m--)
    {
        long long x = a[0];
        answer = (answer + (x % MOD) * pow2[m - 1] % MOD) % MOD;
        for (int i = 0; i < m; i++)
            a[i] -= x;
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<>> pq;
        for (int i = 0; i < m - 1; i++)
            pq.push({a[i] + a[i + 1], i, i + 1});
        vector<long long> b;
        for (int t = 0; t < m - 1; t++)
        {
            auto [sum, i, j] = pq.top();
            pq.pop();
            b.push_back(sum);
            j++;
            if (j < m)
                pq.push({a[i] + a[j], i, j});
        }
        a = b;
    }
    long long remaining = 0;
    if (!a.empty())
        remaining = ((a[0] % MOD) + MOD) % MOD;
    answer = (answer + remaining) % MOD;
    cout << answer % MOD << endl;
    return 0;
}