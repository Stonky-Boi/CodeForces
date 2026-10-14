#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> c(n, vector<int>(k));
    map<vector<int>, int> freq;
    for (vector<int> &v : c)
    {
        for (int &i : v)
            cin >> i;
        freq[v] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            vector<int> v(k);
            for (int l = 0; l < k; l++)
                v[l] = c[i][l] == c[j][l] ? c[i][l] : 3 - c[i][l] - c[j][l];
            if (freq.count(v))
                freq[v]++;
        }
    }
    long long metasets = 0;
    for (const auto &[_, f] : freq)
        metasets += 1ll * f * (f - 1) / 2;
    cout << metasets << endl;
    return 0;
}