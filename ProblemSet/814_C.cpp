#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int q;
    cin >> q;
    int prefix_counts[26][n + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int c = 0; c < 26; c++)
            prefix_counts[c][i + 1] = prefix_counts[c][i];
        prefix_counts[s[i] - 'a'][i + 1]++;
    }
    int answer[26][n + 1] = {0};
    for (int c = 0; c < 26; c++)
    {
        int max_len_for_cost[n + 1] = {0};
        for (int l = 1; l <= n; l++)
            for (int r = l; r <= n; r++)
            {
                int length = r - l + 1;
                int tc = prefix_counts[c][r] - prefix_counts[c][l - 1];
                int cost = length - tc;
                if (cost <= n)
                    max_len_for_cost[cost] = max(max_len_for_cost[cost], length);
            }
        for (int i = 1; i <= n; i++)
            max_len_for_cost[i] = max(max_len_for_cost[i], max_len_for_cost[i - 1]);
        for (int i = 0; i <= n; i++)
            answer[c][i] = max_len_for_cost[i];
    }
    while (q--)
    {
        int m;
        char c;
        cin >> m >> c;
        int ci = c - 'a';
        if (m > n)
            m = n;
        cout << answer[ci][m] << endl;
    }
    return 0;
}