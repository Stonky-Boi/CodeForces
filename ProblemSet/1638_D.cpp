#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> canvas(n, vector<int>(m));
    for (vector<int> &v : canvas)
        for (int &i : v)
            cin >> i;
    vector<vector<bool>> removed(n, vector<bool>(m, false));
    vector<vector<bool>> used(n - 1, vector<bool>(m - 1, false));
    queue<pair<int, int>> q;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < m - 1; j++)
            q.push({i, j});
    vector<tuple<int, int, int>> order;
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        if (used[x][y])
            continue;
        int color = -1;
        bool valid = true;
        for (int i = x; i <= x + 1; i++)
        {
            for (int j = y; j <= y + 1; j++)
            {
                if (removed[i][j])
                    continue;
                if (color == -1)
                    color = canvas[i][j];
                else if (color != canvas[i][j])
                    valid = false;
            }
        }
        if (!valid || color == -1)
            continue;
        used[x][y] = true;
        order.push_back({x + 1, y + 1, color});
        for (int i = x; i <= x + 1; i++)
        {
            for (int j = y; j <= y + 1; j++)
            {
                if (removed[i][j])
                    continue;
                removed[i][j] = true;
                for (int dx = -1; dx <= 0; dx++)
                {
                    for (int dy = -1; dy <= 0; dy++)
                    {
                        int nx = i + dx;
                        int ny = j + dy;
                        if (nx >= 0 && nx < n - 1 && ny >= 0 && ny < m - 1 && !used[nx][ny])
                            q.push({nx, ny});
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!removed[i][j])
            {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    reverse(order.begin(), order.end());
    cout << order.size() << endl;
    for (auto [i, j, c] : order)
        cout << i << ' ' << j << ' ' << c << endl;
    return 0;
}