#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    long long sum = 1ll * n * (n + 1) / 2;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] != a[i + 1])
            sum += 1ll * (i + 1) * (n - i - 1);
    }
    while (m--)
    {
        int i, x;
        cin >> i >> x;
        i--;
        if (i > 0 && a[i - 1] != a[i])
            sum -= 1ll * i * (n - i);
        if (i < n - 1 && a[i] != a[i + 1])
            sum -= 1ll * (i + 1) * (n - i - 1);
        a[i] = x;
        if (i > 0 && a[i - 1] != a[i])
            sum += 1ll * i * (n - i);
        if (i < n - 1 && a[i] != a[i + 1])
            sum += 1ll * (i + 1) * (n - i - 1);
        cout << sum << endl;
    }
    return 0;
}