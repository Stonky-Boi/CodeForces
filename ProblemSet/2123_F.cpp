#include <iostream>
using namespace std;

const int MAXN = 100000;

int main()
{
    bool is_composite[MAXN];
    int primes[MAXN];
    int prime_count = 0;
    for (int i = 2; i * i < MAXN; i++)
        if (!is_composite[i])
            for (int j = i * i; j < MAXN; j += i)
                is_composite[j] = true;
    for (int i = 2; i < MAXN; i++)
        if (!is_composite[i])
            primes[prime_count++] = i;
    int t;
    cin >> t;
    while (t--)
    {
        long int n;
        cin >> n;
        long int p[n + 1], group[n + 1];
        bool assigned[n + 1];
        for (int i = 1; i <= n; i++)
        {
            p[i] = 0;
            assigned[i] = false;
        }
        for (int i = prime_count - 1; i >= 0; i--)
        {
            int prime = primes[i];
            if (prime > n)
                continue;
            int k = 0;
            for (int j = prime; j <= n; j += prime)
            {
                if (!assigned[j])
                {
                    group[k++] = j;
                    assigned[j] = true;
                }
            }
            for (int j = 0; j < k; j++)
                p[group[j]] = group[(j + 1) % k];
        }
        for (int i = 1; i <= n; i++)
            if (p[i] == 0)
                p[i] = i;
        for (int i = 1; i <= n; i++)
            cout << p[i] << "";
        cout << endl;
    }
    return 0;
}