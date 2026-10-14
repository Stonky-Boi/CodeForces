#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int MOD = 1e9 + 7;
    vector<long long> factorial(2e5 + 1, 1);
    for (int i = 2; i <= 2e5; i++)
        factorial[i] = factorial[i - 1] * i % MOD;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        int min_value = 1e9;
        for (int &i : a)
        {
            cin >> i;
            min_value = min(min_value, i);
        }
        int min_count = 0;
        bool valid = true;
        for (const int &i : a)
        {
            if (i == min_value)
                min_count++;
            if ((i & min_value) != min_value)
                valid = false;
        }
        if (min_count == 1 || !valid)
        {
            cout << 0 << endl;
            continue;
        }
        long long permutations = 1ll * min_count * (min_count - 1) % MOD;
        permutations = permutations * factorial[n - 2] % MOD;
        cout << permutations << endl;
    }
    return 0;
}