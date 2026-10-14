#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    int MAXA = 3e5;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    int s, t;
    cin >> s >> t;
    s--;
    t--;
    vector<int> spf(MAXA + 1); // smallest prime factor
    for (int i = 2; i <= MAXA; i++)
    {
        if (spf[i] == 0)
        {
            for (int j = i; j <= MAXA; j += i)
            {
                if (spf[j] == 0)
                    spf[j] = i;
            }
        }
    }
    vector<vector<int>> adj(MAXA + 1); // primes to spiders
    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        while (x > 1)
        {
            int p = spf[x];
            adj[p].push_back(i);
            while (x % p == 0)
                x /= p;
        }
    }
    vector<int> parent(n, -1);
    vector<bool> visited(n, false);
    vector<bool> used_prime(MAXA + 1, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (u == t)
            break;
        int x = a[u];
        while (x > 1)
        {
            int p = spf[x];
            if (!used_prime[p])
            {
                used_prime[p] = true;
                for (int v : adj[p])
                {
                    if (!visited[v])
                    {
                        visited[v] = true;
                        parent[v] = u;
                        q.push(v);
                    }
                }
            }
            while (x % p == 0)
                x /= p;
        }
    }
    if (!visited[t])
    {
        cout << -1 << endl;
        return 0;
    }
    vector<int> path;
    int curr = t;
    while (curr != -1)
    {
        path.push_back(curr + 1);
        curr = parent[curr];
    }
    reverse(path.begin(), path.end());
    cout << path.size() << endl;
    for (const int &v : path)
        cout << v << " ";
    cout << endl;
    return 0;
}