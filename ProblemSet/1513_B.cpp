#include <iostream>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;

int main()
{
    long long factorials[200001];
    factorials[0] = 1;
    for (int i = 1; i < 200001; i++)
        factorials[i] = (factorials[i - 1] * i) % MOD;
    int t;
    cin >> t;
    while (t--)
    {
        long n;
        cin >> n;
        long long a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        long long min_value = a[0];
        for (auto x : a)
            min_value = min(min_value, x);
        int count_min = 0;
        bool valid = true;
        for (auto x : a)
        {
            if (x == min_value)
                count_min++;
            if ((min_value & x) != min_value)
                valid = false;
        }
        if (count_min < 2 || !valid)
        {
            cout << 0 << endl;
            continue;
        }
        long long ways = (1LL * count_min * (count_min - 1)) % MOD;
        ways = (ways * factorials[n - 2]) % MOD;
        cout << ways << endl;
    }
    return 0;
}