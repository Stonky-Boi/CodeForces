#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> start(n + 2), finish(n + 2);
        for (int i = 0; i < m; i++)
        {
            int l, r;
            cin >> l >> r;
            start[l].push_back(i);
            finish[r].push_back(i);
        }
        vector<bool> active(m, false);
        vector<long long> dp(n + 1, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int id : start[i])
            {
                active[id] = true;
                pq.push({i, id});
                count++;
            }
            while (!pq.empty() && !active[pq.top().second])
                pq.pop();
            dp[i] = dp[i - 1];
            if (!pq.empty())
            {
                int x = pq.top().first;
                dp[i] = max(dp[i], dp[x - 1] + count);
            }
            for (int id : finish[i])
            {
                active[id] = false;
                count--;
            }
        }
        cout << dp[n] << endl;
    }
    return 0;
}