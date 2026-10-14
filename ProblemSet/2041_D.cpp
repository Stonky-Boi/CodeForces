#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct state
{
    int row, column, direction, count, distance;
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> maze(n, vector<char>(m));
    int sr = -1, sc = -1, tr = -1, tc = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> maze[i][j];
            if (maze[i][j] == 'S')
                sr = i, sc = j;
            if (maze[i][j] == 'T')
                tr = i, tc = j;
        }
    }
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    vector<vector<vector<vector<bool>>>> visited(n, vector<vector<vector<bool>>>(m, vector<vector<bool>>(4, vector<bool>(4, false))));
    queue<state> q;
    q.push({sr, sc, -1, 0, 0});
    while (!q.empty())
    {
        state curr = q.front();
        q.pop();
        if (curr.row == tr && curr.column == tc)
        {
            cout << curr.distance << endl;
            return 0;
        }
        for (int d = 0; d < 4; d++)
        {
            int nr = curr.row + dr[d];
            int nc = curr.column + dc[d];
            if (maze[nr][nc] == '#')
                continue;
            int count = (d == curr.direction) ? curr.count + 1 : 1;
            if (count > 3)
                continue;
            if (!visited[nr][nc][d][count])
            {
                visited[nr][nc][d][count] = true;
                q.push({nr, nc, d, count, curr.distance + 1});
            }
        }
    }
    cout << -1 << endl;
    return 0;
}