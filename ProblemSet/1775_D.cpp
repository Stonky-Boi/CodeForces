#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int max_a = 300000;
    for (int &i : a)
        cin >> i;
    int s, t;
    cin >> s >> t;
    s--;
    t--;
    if (s == t)
    {
        cout << 1 << endl;
        cout << s + 1 << endl;
        return 0;
    }
    vector<int> prime_factor(max_a + 1);
    for (int i = 0; i <= max_a; i++)
        prime_factor[i] = i;
    for (int i = 2; i * i <= max_a; i++)
    {
        if (prime_factor[i] == i)
        {
            for (int j = i * i; j <= max_a; j += i)
            {
                if (prime_factor[j] == j)
                    prime_factor[j] = i;
            }
        }
    }
    vector<vector<int>> factors(n);
    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        while (x > 1)
        {
            int p = prime_factor[x];
            factors[i].push_back(p);
            while (x % p == 0)
                x /= p;
        }
    }
    vector<vector<int>> divisible(max_a + 1);
    for (int i = 0; i < n; i++)
    {
        for (int p : factors[i])
            divisible[p].push_back(i);
    }
    vector<int> parent(n, -1);
    vector<bool> visited(n, false);
    vector<bool> used_prime(max_a + 1, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        if (v == t)
            break;
        for (int p : factors[v])
        {
            if (used_prime[p])
                continue;
            used_prime[p] = true;
            for (int u : divisible[p])
            {
                if (visited[u])
                    continue;
                visited[u] = true;
                parent[u] = v;
                q.push(u);
            }
        }
    }
    if (!visited[t])
    {
        cout << -1 << endl;
        return 0;
    }
    vector<int> path;
    for (int v = t; v != -1; v = parent[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    cout << path.size() << endl;
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] + 1;
        if (i + 1 < path.size())
            cout << ' ';
    }
    cout << endl;
    return 0;
}