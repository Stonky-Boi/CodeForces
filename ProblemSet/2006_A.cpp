#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
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
        string s;
        cin >> s;
        int zeroes = 0, ones = 0, q_leaf = 0, q_other = 0;
        for (int i = 1; i < n; i++)
        {
            if (degree[i] == 1)
            {
                if (s[i] == '0')
                    zeroes++;
                else if (s[i] == '1')
                    ones++;
                else
                    q_leaf++;
            }
            else if (s[i] == '?')
                q_other++;
        }
        if (s[0] != '?')
            cout << ((s[0] == '1' ? zeroes : ones) + (q_leaf + 1) / 2) << endl;
        else
        {
            if (zeroes == ones && (q_other % 2 == 1))
                cout << (zeroes + (q_leaf + 1) / 2) << endl;
            else
                cout << (max(zeroes, ones) + q_leaf / 2) << endl;
        }
    }
    return 0;
}