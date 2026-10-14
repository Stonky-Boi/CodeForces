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
        vector<int> u(n), s(n);
        for (int &i : u)
            cin >> i;
        for (int &i : s)
            cin >> i;
        vector<vector<long long>> universities(n);
        for (int i = 0; i < n; i++)
            universities[u[i] - 1].push_back(s[i]);
        vector<long long> strength(n, 0);
        for (vector<long long> &v : universities)
        {
            sort(v.begin(), v.end(), greater<long long>());
            int m = v.size();
            for (int j = 1; j < m; j++)
                v[j] += v[j - 1];
            for (int k = 1; k <= m; k++)
            {
                int remaining = (m / k) * k;
                if (remaining > 0)
                    strength[k - 1] += v[remaining - 1];
            }
        }
        for (const long long &i : strength)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}