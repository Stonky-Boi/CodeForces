#include <iostream>
using namespace std;

int main()
{
    int MOD = 1e9 + 7;
    string s;
    cin >> s;
    long long sequences = 1;
    int count = 0;
    for (const char &c : s)
    {
        if (c == 'a')
            count++;
        else if (c == 'b')
        {
            sequences = sequences * (count + 1) % MOD;
            count = 0;
        }
    }
    sequences = sequences * (count + 1) % MOD;
    cout << (sequences - 1 + MOD) % MOD << endl;
    return 0;
}