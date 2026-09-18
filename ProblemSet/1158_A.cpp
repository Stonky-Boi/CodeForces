#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    long long b[n], g[m];
    long long sweets = 0;
    for (auto &x : b)
    {
        cin >> x;
        sweets += x;
    }
    sweets *= m;
    for (auto &x : g)
        cin >> x;
    sort(b, b + n);
    sort(g, g + m);
    if (b[n - 1] > g[0])
    {
        cout << -1;
        return 0;
    }
    for (int i = 1; i < m; i++)
        sweets += g[i] - b[n - 1];
    if (g[0] != b[n - 1])
        sweets += g[0] - b[n - 2];
    cout << sweets << endl;
    return 0;
}