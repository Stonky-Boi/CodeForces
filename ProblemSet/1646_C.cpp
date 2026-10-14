#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<long long> factorials;
    long long f = 1;
    for (int i = 1; i <= 14; i++)
    {
        f *= i;
        if (i >= 3)
            factorials.push_back(f);
    }
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        int k = __builtin_popcountll(n);
        int m = factorials.size();
        for (int i = 1; i < (1 << m); i++)
        {
            long long sum = 0;
            int count = 0;
            for (int j = 0; j < m; j++)
            {
                if (i & (1 << j))
                {
                    sum += factorials[j];
                    count++;
                }
            }
            if (sum <= n)
            {
                int bits = __builtin_popcountll(n - sum);
                k = min(k, count + bits);
            }
        }
        cout << k << endl;
    }
    return 0;
}