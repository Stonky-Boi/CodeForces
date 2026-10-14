#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long INF = 4e18;
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> right(n, vector<int>(m - 1));
    vector<vector<int>> down(n - 1, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m - 1; j++)
            cin >> right[i][j];
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> down[i][j];
    }
    if (k % 2 == 1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << -1 << " ";
            cout << endl;
        }
        return 0;
    }
    vector<vector<long long>> curr(n, vector<long long>(m, 0));
    vector<vector<long long>> next(n, vector<long long>(m, INF));
    for (int step = 0; step < k / 2; step++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                next[i][j] = INF;
                if (i > 0)
                    next[i][j] = min(next[i][j], curr[i - 1][j] + down[i - 1][j]);
                if (i < n - 1)
                    next[i][j] = min(next[i][j], curr[i + 1][j] + down[i][j]);
                if (j > 0)
                    next[i][j] = min(next[i][j], curr[i][j - 1] + right[i][j - 1]);
                if (j < m - 1)
                    next[i][j] = min(next[i][j], curr[i][j + 1] + right[i][j]);
            }
        }
        curr.swap(next);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << 2 * curr[i][j] << " ";
        cout << endl;
    }
    return 0;
}