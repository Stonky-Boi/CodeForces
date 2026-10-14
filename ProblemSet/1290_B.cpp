#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> prefix_count(n + 1, vector<int>(26, 0));
    for (int i = 0; i < n; i++)
    {
        prefix_count[i + 1] = prefix_count[i];
        prefix_count[i + 1][s[i] - 'a']++;
    }
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if (l == r || s[l] != s[r])
        {
            cout << "Yes" << endl;
            continue;
        }
        int distinct = 0;
        for (int i = 0; i < 26; i++)
        {
            if (prefix_count[r + 1][i] - prefix_count[l][i] > 0)
                distinct++;
        }
        cout << (distinct >= 3 ? "Yes" : "No") << endl;
    }
    return 0;
}