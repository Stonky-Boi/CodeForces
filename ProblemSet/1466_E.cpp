#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int MOD = 1e9 + 7;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n);
        vector<long long> count(60, 0);
        vector<long long> power(60, 1);
        for (int b = 1; b < 60; b++)
            power[b] = (power[b - 1] * 2) % MOD;
        for (long long &i : a)
        {
            cin >> i;
            for (int b = 0; b < 60; b++)
            {
                if ((i >> b) & 1ll)
                    count[b]++;
            }
        }
        long long value = 0;
        for (int i = 0; i < n; i++)
        {
            long long A = 0;
            long long B = 0;
            for (int b = 0; b < 60; b++)
            {
                if ((a[i] >> b) & 1ll)
                {
                    A = (A + count[b] * power[b]) % MOD;
                    B = (B + n * power[b]) % MOD;
                }
                else
                    B = (B + count[b] * power[b]) % MOD;
            }
            value = (value + A * B) % MOD;
        }
        cout << value << endl;
    }
    return 0;
}