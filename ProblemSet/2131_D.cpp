#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long int n;
        cin >> n;
        vector<vector<int>> tree(n);
        vector<int> degree(n, 0);
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            tree[u].push_back(v);
            tree[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        if (n <= 3)
        {
            cout << "0" << endl;
            continue;
        }
        int leaves = 0;
        for (int i = 0; i < n; i++)
            if (degree[i] == 1)
                leaves++;
        int max_leaf_neighbours = 0;
        for (int i = 0; i < n; i++)
        {
            int leaf_neighbors = 0;
            for (int j = 0; j < tree[i].size(); j++)
                if (degree[tree[i][j]] == 1)
                    leaf_neighbors++;
            max_leaf_neighbours = max(max_leaf_neighbours, leaf_neighbors);
        }
        cout << leaves - max_leaf_neighbours << endl;
    }
    return 0;
}