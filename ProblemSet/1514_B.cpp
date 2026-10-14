#include <iostream>
using namespace std;

int main()
{
    int MOD = 1e9 + 7;
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        long long arrays = 1;
        for (int i = 0; i < k; i++)
            arrays = (arrays * n) % MOD;
        cout << arrays << endl;
    }
    return 0;
}