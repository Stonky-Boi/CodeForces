#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    long long int n[t], k[t];
    for (int i = 0; i < t; i++)
        cin >> n[i];
    for (int i = 0; i < t; i++)
        cin >> k[i];
    long int precompute[100000] = {1};
    for (long int p = 1; p < 100000; p++)
        precompute[p] = (2 * precompute[p - 1]) % 1000000007;
    for (int i = 0; i < t; i++)
    {
        if (k[i] < n[i])
            cout << precompute[k[i]] << endl;
        else
            cout << 1 << endl;
    }
    return 0;
}