#include <iostream>
using namespace std;

int main()
{
    int MOD = 1e9 + 7;
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        // sum(i^2) from 1 to n + sum(i*(i+1)) from 1 to n-1
        // this gives 2022 * n * (n+1) * (4n-1) / 6
        long long sum = (n * (n + 1)) % MOD;
        sum = (sum * (4 * n - 1)) % MOD;
        cout << (sum * 337) % MOD << endl;
    }
    return 0;
}