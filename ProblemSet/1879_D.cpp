#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 998244353;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    long long result = 0;
    for (int b = 0; b <= 30; b++)
    {
        vector<int> prefix_parity(n + 1, 0);
        for (int i = 1; i <= n; i++)
            prefix_parity[i] = prefix_parity[i - 1] ^ ((a[i] >> b) & 1);
        long long count[2] = {0, 0};
        long long sumL[2] = {0, 0};
        count[0] = 1;
        sumL[0] = 0;
        for (int r = 1; r <= n; r++)
        {
            int p = prefix_parity[r];
            int complement = 1 - p;
            long long contribution = (r * count[complement] - sumL[complement]) % MOD;
            if (contribution < 0)
                contribution += MOD;
            result = (result + (contribution << b) % MOD) % MOD;
            count[p] += 1;
            sumL[p] = (sumL[p] + r) % MOD;
        }
    }
    cout << result << endl;
    return 0;
}