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
        int n;
        cin >> n;
        vector<vector<int>> a(n);
        vector<pair<int, int>> caves(n);
        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            a[i].resize(k);
            int need = 0;
            for (int j = 0; j < k; j++)
            {
                cin >> a[i][j];
                need = max(need, a[i][j] - j + 1);
            }
            caves[i] = {need, k};
        }
        sort(caves.begin(), caves.end());
        int killed = 0;
        int min_power = 0;
        for (const auto &[need, monsters] : caves)
        {
            min_power = max(min_power, need - killed);
            killed += monsters;
        }
        cout << min_power << endl;
    }
    return 0;
}