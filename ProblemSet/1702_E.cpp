#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> adj(n);
        vector<int> count(n, 0);
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
            count[a]++;
            count[b]++;
        }
        bool possible = true;
        for (const int &i : count)
        {
            if (i != 2)
            {
                possible = false;
                break;
            }
        }
        if (possible)
        {
            vector<bool> visited(n, false);
            for (int i = 0; i < n; i++)
            {
                if (visited[i])
                    continue;
                int prev = -1, curr = i;
                int length = 0;
                while (!visited[curr])
                {
                    visited[curr] = true;
                    length++;
                    int next = (adj[curr][0] == prev ? adj[curr][1] : adj[curr][0]);
                    prev = curr;
                    curr = next;
                }
                if (length % 2 != 0)
                {
                    possible = false;
                    break;
                }
            }
        }
        cout << (possible ? "YES" : "NO") << endl;
    }
    return 0;
}