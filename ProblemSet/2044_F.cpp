#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n), b(m);
    vector<int> freq_a(2 * n + 1, 0), freq_b(2 * m + 1, 0);
    long long sum_a = 0, sum_b = 0;
    for (int &i : a)
    {
        cin >> i;
        sum_a += i;
        freq_a[i + n]++;
    }
    for (int &i : b)
    {
        cin >> i;
        sum_b += i;
        freq_b[i + m]++;
    }
    while (q--)
    {
        int x;
        cin >> x;
        bool valid = false;
        for (int i = 1; i * i <= abs(x); i++)
        {
            if (x % i != 0)
                continue;
            int j = x / i;
            for (int sign : {1, -1})
            {
                int u = sign * i;
                int v = sign * j;
                if (sum_a - u >= -n && sum_a - u <= n && sum_b - v >= -m && sum_b - v <= m &&
                    freq_a[sum_a - u + n] > 0 && freq_b[sum_b - v + m] > 0)
                {
                    valid = true;
                    break;
                }
                if (sum_a - v >= -n && sum_a - v <= n && sum_b - u >= -m && sum_b - u <= m &&
                    freq_a[sum_a - v + n] > 0 && freq_b[sum_b - u + m] > 0)
                {
                    valid = true;
                    break;
                }
            }
            if (valid)
                break;
        }
        cout << (valid ? "YES" : "NO") << endl;
    }
    return 0;
}