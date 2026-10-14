#include <iostream>
#include <vector>
#include <set>
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
        vector<vector<int>> a(n, vector<int>(m));
        set<vector<int>> s;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
            vector<int> inverse(m);
            for (int j = 0; j < m; j++)
                inverse[a[i][j] - 1] = j + 1;
            s.insert(inverse);
        }
        for (int i = 0; i < n; i++)
        {
            int beauty = 0;
            for (int k = m; k >= 1; k--)
            {
                vector<int> p;
                for (int j = 0; j < k; j++)
                    p.push_back(a[i][j]);
                auto it = s.lower_bound(p);
                if (it != s.end() && equal(p.begin(), p.end(), it->begin()))
                {
                    beauty = k;
                    break;
                }
            }
            cout << beauty << " ";
        }
        cout << endl;
    }
    return 0;
}