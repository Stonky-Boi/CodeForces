#include <iostream>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    long long int a[n], l[m], r[m], d[m], x[k], y[k];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> l[i] >> r[i] >> d[i];
    for (int i = 0; i < k; i++)
        cin >> x[i] >> y[i];
    long long int op_count[m + 1] = {0}, delta[n + 1] = {0};
    for (int i = 0; i < k; i++)
    {
        int from = x[i] - 1;
        int to = y[i] - 1;
        op_count[from] += 1;
        op_count[to + 1] -= 1;
    }
    for (int i = 1; i < m; i++)
        op_count[i] += op_count[i - 1];
    for (int i = 0; i < m; i++)
    {
        long int times = op_count[i];
        int left = l[i] - 1;
        int right = r[i] - 1;
        delta[left] += d[i] * times;
        delta[right + 1] -= d[i] * times;
    }
    long long int current = 0;
    for (int i = 0; i < n; i++)
    {
        current += delta[i];
        cout << a[i] + current << " ";
    }
    cout << endl;
    return 0;
}