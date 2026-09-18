#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<long long> compute_t_smallest(const vector<long long> &v, int t)
{
    int m = (int)v.size();
    vector<long long> result;
    if (m < 2 || t <= 0)
        return result;
    priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<>> pq;
    for (int i = 0; i < m - 1; i++)
        pq.push({v[i] + v[i + 1], i, i + 1});
    while (t-- && !pq.empty())
    {
        auto [sum, i, j] = pq.top();
        pq.pop();
        result.push_back(sum);
        j++;
        if (j < m)
            pq.push({v[i] + v[j], i, j});
    }
    return result;
};

int main()
{
    const long long MOD = 1000000007;
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int K = 64;
    if (K > n)
        K = n;
    vector<long long> pow2(n + 1);
    pow2[0] = 1;
    for (int i = 1; i <= n; ++i)
        pow2[i] = (pow2[i - 1] * 2) % MOD;
    long long answer = 0;
    vector<long long> curr;
    for (int i = 0; i < K; ++i)
        curr.push_back(a[i]);
    int m = n;
    while (m > K)
    {
        long long x = curr[0];
        answer = (answer + (x % MOD) * pow2[m - 1] % MOD) % MOD;
        for (int i = 0; i < (int)curr.size(); ++i)
            curr[i] -= x;
        curr = compute_t_smallest(curr, K);
        m--;
    }
    while (m > 1)
    {
        long long x = curr[0];
        answer = (answer + (x % MOD) * pow2[m - 1] % MOD) % MOD;
        for (int i = 0; i < (int)curr.size(); ++i)
            curr[i] -= x;
        curr = compute_t_smallest(curr, m - 1);
        m--;
    }
    long long remaining = 0;
    if (!curr.empty())
        remaining = ((curr[0] % MOD) + MOD) % MOD;
    answer = (answer + remaining) % MOD;
    cout << answer % MOD << endl;
    return 0;
}