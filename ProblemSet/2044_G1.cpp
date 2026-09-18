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
        vector<int> dp(n, 0);
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        int max_depth = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            int v = r[u];
            dp[v] = max(dp[v], dp[u] + 1);
            max_depth = max(max_depth, dp[v]);
            if (--indegree[v] == 0)
                q.push(v);
        }
        cout << max_depth + 2 << endl;
    }
    return 0;
}