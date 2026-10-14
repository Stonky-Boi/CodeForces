#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> a(k, vector<int>(n));
        for (vector<int> &v : a)
            for (int &i : v)
                cin >> i;
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for (int i = 0; i < k; i++)
        {
            for (int j = 1; j < n - 1; j++)
            {
                int u = a[i][j] - 1;
                int v = a[i][j + 1] - 1;
                adj[u].push_back(v);
                indegree[v]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        int count = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            count++;
            for (int v : adj[u])
            {
                indegree[v]--;
                if (indegree[v] == 0)
                    q.push(v);
            }
        }
        cout << (count == n ? "YES" : "NO") << endl;
    }
    return 0;
}