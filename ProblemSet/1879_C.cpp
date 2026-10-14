#include <iostream>
using namespace std;

int main()
{
    int MOD = 998244353;
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        long long operations = 0, sequences = 1;
        int length = 1;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == s[i - 1])
                length++;
            else
            {
                operations += length - 1;
                sequences = sequences * length % MOD;
                length = 1;
            }
        }
        operations += length - 1;
        sequences = sequences * length % MOD;
        for (int i = 1; i <= operations; i++)
            sequences = sequences * i % MOD;
        cout << operations << " " << sequences << endl;
    }
    return 0;
}