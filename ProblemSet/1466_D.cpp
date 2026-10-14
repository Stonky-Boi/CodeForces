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
        vector<int> w(n);
        long long max_value = 0;
        for (int &i : w)
        {
            cin >> i;
            max_value += i;
        }
        cout << max_value;
        vector<int> degree(n, 0);
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            degree[u]++;
            degree[v]++;
        }
        vector<int> extra;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < degree[i]; j++)
                extra.push_back(w[i]);
        }
        sort(extra.begin(), extra.end(), greater<int>());
        for (const int &i : extra)
        {
            max_value += i;
            cout << " " << max_value;
        }
        cout << endl;
    }
    return 0;
}