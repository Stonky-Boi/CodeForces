#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> c(n, vector<int>(m));
        for (vector<int> &v : c)
            for (int &i : v)
                cin >> i;
        long long winnings = 0;
        vector<int> column(n);
        for (int j = 0; j < m; j++)
        {
            for (int i = 0; i < n; i++)
                column[i] = c[i][j];
            sort(column.begin(), column.end());
            for (int i = 0; i < n; i++)
            {
                winnings += 1ll * column[i] * i;
                winnings -= 1ll * column[i] * (n - i - 1);
            }
        }
        cout << winnings << endl;
    }
    return 0;
}