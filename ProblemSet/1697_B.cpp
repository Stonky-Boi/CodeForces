#include <iostream>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    long long p[n];
    for (auto &i : p)
        cin >> i;
    sort(p, p + n);
    long long prefix[n + 1];
    prefix[0] = 0;
    for (int i = 0; i < n; i++)
        prefix[i + 1] = prefix[i] + p[i];
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        long long free_sum = prefix[n - x + y] - prefix[n - x];
        cout << free_sum << endl;
    }
    return 0;
}