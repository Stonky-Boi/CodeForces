#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int x, y, n, k;
        cin >> x >> y >> n;
        k = n - (n % x) + y;
        if (k > n)
            k -= x;
        cout << k << endl;
    }
    return 0;
}