#include <iostream>
#include <algorithm>
using namespace std;

const long long MOD = 1000000007;

long long P(int i, long long int j, const long long int F[])
{
    if (j == 0)
        return 1;
    long long result = (i + 1) % MOD;
    j--;
    for (int w = 0; w < i && j > 0; w++)
    {
        if (j >= (1LL << w))
        {
            result = (result * F[w]) % MOD;
            j -= (1LL << w);
        }
        else
        {
            result = (result * P(w, j, F)) % MOD;
            break;
        }
    }
    return result % MOD;
}

int main()
{
    long long int F[31];
    F[0] = 1;
    for (int i = 1; i <= 30; i++)
    {
        long long int product = 1;
        for (int j = 0; j < i; j++)
            product = (product * F[j]) % MOD;
        F[i] = ((i + 1) * product) % MOD;
    }
    int t;
    cin >> t;
    while (t--)
    {
        long int n;
        long long int k;
        cin >> n >> k;
        long long int s[n];
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
            s[i]--;
        }
        sort(s, s + n);
        long long int score = 1;
        for (int i = 0; i < n; i++)
        {
            if (k == 0)
                break;
            if (s[i] <= 30)
            {
                long long int block = 1LL << s[i];
                if (k >= block)
                {
                    score = (score * F[s[i]]) % MOD;
                    k -= block;
                }
                else
                {
                    score = (score * P(s[i], k, F)) % MOD;
                    k = 0;
                }
            }
            else
            {
                score = (score * P(s[i], k, F)) % MOD;
                k = 0;
            }
        }
        cout << score % MOD << endl;
    }
    return 0;
}