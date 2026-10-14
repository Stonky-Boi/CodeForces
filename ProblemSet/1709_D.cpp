#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int &i : a)
        cin >> i;
    vector<int> log2(m + 1);
    for (int i = 2; i <= m; i++)
        log2[i] = log2[i / 2] + 1;
    int levels = log2[m] + 1;
    vector<vector<int>> st(levels, vector<int>(m)); // sparse table
    st[0] = a;
    for (int j = 1; j < levels; j++)
    {
        for (int i = 0; i + (1 << j) <= m; i++)
            st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int xs, ys, xf, yf, k;
        cin >> xs >> ys >> xf >> yf >> k;
        if (abs(xs - xf) % k != 0 || abs(ys - yf) % k != 0)
        {
            cout << "NO" << endl;
            continue;
        }
        int highest = xs + ((n - xs) / k) * k;
        if (ys > yf)
            swap(ys, yf);
        ys--;
        yf--;
        int j = log2[yf - ys + 1];
        int blocked = max(st[j][ys], st[j][yf - (1 << j) + 1]);
        cout << (highest > blocked ? "YES" : "NO") << endl;
    }
    return 0;
}