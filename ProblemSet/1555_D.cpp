#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    string s;
    cin >> n >> m >> s;
    vector<string> pattern = {"abc", "acb", "bac", "bca", "cab", "cba"};
    vector<vector<int>> diff(6, vector<int>(n + 1, 0));
    for (int k = 0; k < 6; k++)
    {
        for (int i = 0; i < n; i++)
        {
            char expected = pattern[k][i % 3];
            diff[k][i + 1] = diff[k][i] + (s[i] == expected ? 0 : 1);
        }
    }
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        int min_cost = n;
        for (int k = 0; k < 6; k++)
        {
            int cost = diff[k][r] - diff[k][l - 1];
            min_cost = min(min_cost, cost);
        }
        cout << min_cost << endl;
    }
    return 0;
}