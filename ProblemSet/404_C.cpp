#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> d(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> d[i];
    vector<vector<int>> levels(n);
    for (int i = 1; i <= n; i++)
        levels[d[i]].push_back(i);
    if (levels[0].size() != 1)
    {
        cout << -1 << endl;
        return 0;
    }
    vector<pair<int, int>> edges;
    queue<pair<int, int>> q;
    q.push({levels[0][0], k});
    for (int i = 1; i < n; i++)
    {
        if (levels[i].empty())
            continue;
        if ((!levels[i].empty() && levels[i - 1].empty()) || q.empty())
        {
            cout << -1 << endl;
            return 0;
        }
        queue<pair<int, int>> next;
        int index = 0;
        while (!q.empty())
        {
            auto [parent, capacity] = q.front();
            q.pop();
            while (capacity > 0 && index < levels[i].size())
            {
                int child = levels[i][index++];
                edges.push_back({parent, child});
                next.push({child, k - 1});
                capacity--;
            }
        }
        if (index < levels[i].size())
        {
            cout << -1 << endl;
            return 0;
        }
        q = next;
    }
    cout << edges.size() << endl;
    for (auto [u, v] : edges)
        cout << u << " " << v << endl;
    return 0;
}