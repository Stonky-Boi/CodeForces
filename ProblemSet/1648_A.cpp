#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long distance_sum(vector<int> &points)
{
    sort(points.begin(), points.end());
    long long sum = 0;
    long long prefix = 0;
    for (int i = 0; i < points.size(); i++)
    {
        sum += 1ll * points[i] * i - prefix;
        prefix += points[i];
    }
    return sum;
}

int main()
{
    int n, m;
    cin >> n >> m;
    const int colors = 1e5;
    vector<vector<int>> c(n, vector<int>(m));
    vector<vector<int>> row(colors + 1), column(colors + 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> c[i][j];
            row[c[i][j]].push_back(i);
            column[c[i][j]].push_back(j);
        }
    }
    long long sum = 0;
    for (int c = 1; c <= colors; c++)
        sum += distance_sum(row[c]) + distance_sum(column[c]);
    cout << sum << endl;
    return 0;
}