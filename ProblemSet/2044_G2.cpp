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
        int n;
        cin >> n;
        vector<int> r(n);
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> r[i];
            indegree[--r[i]]++;
        }
        vector<long long> dp(n, 1);
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        long long max_time = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            max_time = max(max_time, dp[u]);
            int v = r[u];
            dp[v] += dp[u];
            if (--indegree[v] == 0)
                q.push(v);
        }
        cout << max_time + 2 << endl;
    }
    return 0;
}