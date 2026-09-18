#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<string> grid;
vector<vector<bool>> visited;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int sx, int sy)
{
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = true;
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
                if (!visited[nx][ny] && grid[nx][ny] != '#')
                {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        grid.resize(n);
        for (auto &i : grid)
            cin >> i;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 'B')
                    for (int d = 0; d < 4; d++)
                    {
                        int ni = i + dx[d];
                        int nj = j + dy[d];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < m)
                            if (grid[ni][nj] == '.')
                                grid[ni][nj] = '#';
                    }
        // visited marks cells from which escape is possible
        visited.assign(n, vector<bool>(m, false));
        // mark all cells reachable from exit
        if (grid[n - 1][m - 1] != '#')
            bfs(n - 1, m - 1);
        bool possible = true;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 'G' && !visited[i][j])
                    possible = false;
                if (grid[i][j] == 'B' && visited[i][j])
                    possible = false;
            }
        cout << (possible ? "YES" : "NO") << endl;
    }
    return 0;
}