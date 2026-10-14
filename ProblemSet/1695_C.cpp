#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (vector<int> &v : a)
            for (int &i : v)
                cin >> i;
        if ((n + m) % 2 == 0)
        {
            cout << "NO" << endl;
            continue;
        }
        vector<vector<int>> minimum(n, vector<int>(m));
        vector<vector<int>> maximum(n, vector<int>(m));
        minimum[0][0] = maximum[0][0] = a[0][0];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                int low = 1e9, high = -1e9;
                if (i > 0)
                {
                    low = min(low, minimum[i - 1][j]);
                    high = max(high, maximum[i - 1][j]);
                }
                if (j > 0)
                {
                    low = min(low, minimum[i][j - 1]);
                    high = max(high, maximum[i][j - 1]);
                }
                minimum[i][j] = low + a[i][j];
                maximum[i][j] = high + a[i][j];
            }
        }
        if (minimum[n - 1][m - 1] <= 0 && maximum[n - 1][m - 1] >= 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}