#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int MOD = 1e9 + 7;
    int MAX_MASK = 1 << 6;
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> curr(MAX_MASK, 0); // dp[i] = number of sequences with AND equal to i
        for (int &i : a)
        {
            cin >> i;
            vector<int> next = curr;
            next[i] = (next[i] + 1) % MOD;
            for (int mask = 0; mask < MAX_MASK; mask++)
            {
                int new_mask = mask & i;
                next[new_mask] = (next[new_mask] + curr[mask]) % MOD;
            }
            curr = next;
        }
        int sequences = 0;
        for (int mask = 0; mask < MAX_MASK; mask++)
        {
            int bits = __builtin_popcount(mask);
            if (bits == k)
                sequences = (sequences + curr[mask]) % MOD;
        }
        cout << sequences << endl;
    }
    return 0;
}