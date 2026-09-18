#include <iostream>
#include <numeric>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        long long int k = a[1] - a[0];
        for (int i = 1; i < n - 1; i++)
            k = gcd(k, a[i + 1] - a[i]);
        k *= 2;
        cout << k << endl;
    }
    return 0;
}