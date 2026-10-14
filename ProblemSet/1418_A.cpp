#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, k;
        cin >> x >> y >> k;
        long long n = 1ll * y * k + k - 1, d = x - 1;
        cout << (n + d - 1) / d + k << endl;
    }
    return 0;
}