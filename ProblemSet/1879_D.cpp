#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int MOD = 998244353;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    long long value = 0;
    long long power = 1;
    for (int b = 0; b < 31; b++)
    {
        long long count[2] = {1, 0};
        long long sum[2] = {0, 0};
        int parity = 0;
        long long contribution = 0;
        for (int i = 1; i <= n; i++)
        {
            if ((a[i - 1] >> b) & 1)
                parity ^= 1;
            int other = 1 - parity;
            contribution = (contribution + i * count[other] - sum[other]) % MOD;
            count[parity]++;
            sum[parity] += i;
        }
        value = (value + contribution * power) % MOD;
        power = (power * 2) % MOD;
    }
    cout << (value + MOD) % MOD << endl;
    return 0;
}